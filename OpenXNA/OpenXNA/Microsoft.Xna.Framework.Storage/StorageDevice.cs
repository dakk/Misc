using System;

namespace Microsoft.Xna.Framework.Storage
{
	public sealed class StorageDevice
	{
		public long TotalSpace { get; set; }
		public long FreeSpace { get; set; }
		/* Gets whether the device is connected. */
		public bool IsConnected { get; set; }
		
		public StorageDevice ()
		{
		}
		/*
		public IAsyncResult BeginOpenContainer ( string displayName,
										         AsyncCallback callback,
										         Object state )
		{
			return new IAsyncResult();
		}*/
		
		public void DeleteContainer ( string titleName )
		{
			
		}
			
		public static event EventHandler<EventArgs> DeviceChanged;
	}
}

