(*
	Copyright (c) 2012, Davide Gessa (dakk)
	All rights reserved.

	Redistribution and use in source and binary forms, with or without modification, are permitted provided 
	that the following conditions are met:

	-	Redistributions of source code must retain the above copyright notice, this list of conditions and the 
		following disclaimer.
	-	Redistributions in binary form must reproduce the above copyright notice, this list of conditions and 
		the following disclaimer in the documentation and/or other materials provided with the distribution.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED 
	WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A 
	PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR 
	ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED 
	TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
	HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
	NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
	POSSIBILITY OF SUCH DAMAGE.
 *)
(* ocamlopt -I +lablGL lablgl.cmxa lablglut.cmxa julia_set.ml -o julia_set *)


(* Calculate the julia set iteration in a generic point z *)
let julia_calculate c (x,y) imax er =
	let z = {Complex.re=x; Complex.im=y} in
	let rec step i z =
		if Complex.norm(z) > er || i >= imax then i
		else step (i+1) (Complex.add (Complex.mul z z) c)
	in step 0 z
;;


let reshape ~w ~h =
	let w = max 1 w and h = max 1 h in
	GlDraw.viewport 0 0 w h;
	GlMat.mode `projection;
	GlMat.load_identity ();
	GlMat.ortho ~x:(-2., 2.) ~y:(-2., 2.) ~z:(0., 1.);
	GlMat.mode `modelview
  

let display () =
	GlDraw.begins `points;
	for a = 0 to 640 - 1 do
		for b = 0 to 480 - 1 do
			let x = 3. *. float a /. float 640 -. 1.5 in
			let y = 3. *. float b /. float 480 -. 1.5 in
			let i = julia_calculate {Complex.re=(-0.70176); Complex.im=(-0.3842)} (x,y) 255 3.0 in
			let f i = 0.5 +. 0.5 *. cos(float i *. 0.1) in
			GlDraw.color (0.0, 0.0, f(i + 32));
			GlDraw.vertex ~x ~y ()
		done;
	done;
	GlDraw.ends ();
	Gl.flush ()

let () =
	Glut.init Sys.argv;
	Glut.initWindowSize ~w: 640 ~h: 480;
	Glut.createWindow ~title: "Julia set";
	Glut.displayFunc ~cb: display;  
	Glut.reshapeFunc ~cb:reshape;
	Glut.keyboardFunc ~cb: (fun ~key ~x ~y -> if key=27 then exit 0);
	Glut.mainLoop ()
