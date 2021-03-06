#pragma once

using namespace OpenZWave;

namespace OpenZWave
{
	/// <summary>Various LogLevels available to the Application</summary>
	public enum class ZWLogLevel
	{	
		/// <summary>Disable all logging</summary>
		None = LogLevel_None,				   
		/// <summary>These messages should always be shown</summary>
		Always = LogLevel_Always,			   
		/// <summary>A likely fatal issue in the library</summary>
		Fatal = LogLevel_Fatal,				   
		/// <summary>A serious issue with the library or the network</summary>
		Error = LogLevel_Error,				   
		/// <summary>A minor issue from which the library should be able to recover</summary>
		Warning = LogLevel_Warning,			               
		/// <summary>Something unexpected by the library about which the controlling application should be aware</summary>
		Alert = LogLevel_Alert,				   			   
		/// <summary>Everything is working fine...these messages provide streamlined feedback on each message</summary>
		Info = LogLevel_Info,				   			   
		/// <summary>Detailed information on the progress of each message</summary>
		Detail = LogLevel_Detail,			   			   
		/// <summary>Very detailed information on progress that will create a huge log file quickly. But this level (as others) can be queued and sent to the log only on an error or warning</summary>
		Debug = LogLevel_Debug,				   			   
		/// <summary>Will include low-level byte transfers from controller to buffer to application and back</summary>
		StreamDetail = LogLevel_StreamDetail,  			   
		/// <summary>Used only within the log class (uses existing timestamp, etc.)</summary>
		Internal = LogLevel_Internal           
	};

	// Controller interface types
	public enum class ZWControllerInterface
	{
		Unknown = Driver::ControllerInterface_Unknown,
		Serial = Driver::ControllerInterface_Serial,
		Hid = Driver::ControllerInterface_Hid
	};

	public enum class ZWOptionType
	{
		Invalid = Options::OptionType_Invalid,
		Bool = Options::OptionType_Bool,
		Int = Options::OptionType_Int,
		String = Options::OptionType_String
	};

	/// <summary>Notification types.</summary>
	/// <remarks>Notifications of various Z-Wave events sent to the watchers
	/// registered with the Manager::AddWatcher method.</remarks>
	public enum class ZWNotificationType
	{
		/// <summary>A new node value has been added to OpenZWave's list. These notifications occur after a node has been discovered, and details of its command classes have been received.  Each command class may generate one or more values depending on the complexity of the item being represented.</summary> 
		ValueAdded = Notification::Type_ValueAdded,
		/// <summary>A node value has been removed from OpenZWave's list.  This only occurs when a node is removed.</summary>
		ValueRemoved = Notification::Type_ValueRemoved,
		/// <summary>A node value has been updated from the Z-Wave network and it is different from the previous value.</summary>
		ValueChanged = Notification::Type_ValueChanged,
		/// <summary>A node value has been updated from the Z-Wave network.</summary>
		ValueRefreshed = Notification::Type_ValueRefreshed,
		/// <summary>The associations for the node have changed. The application should rebuild any group information it holds about the node.</summary>
		Group = Notification::Type_Group,
		/// <summary>A new node has been found (not already stored in zwcfg*.xml file) </summary>
		NodeNew = Notification::Type_NodeNew,
		/// <summary>A new node has been added to OpenZWave's list.  This may be due to a device being added to the Z-Wave network, or because the application is initializing itself.</summary>
		NodeAdded = Notification::Type_NodeAdded,
		/// <summary>A node has been removed from OpenZWave's list.  This may be due to a device being removed from the Z-Wave network, or because the application is closing.</summary>
		NodeRemoved = Notification::Type_NodeRemoved,
		/// <summary>Basic node information has been received, such as whether the node is a listening device, a routing device and its baud rate and basic, generic and specific types. It is after this notification that you can call Manager::GetNodeType to obtain a label containing the device description.</summary> 
		NodeProtocolInfo = Notification::Type_NodeProtocolInfo,
		/// <summary> One of the node names has changed (name, manufacturer, product).</summary>
		NodeNaming = Notification::Type_NodeNaming,
		/// <summary>A node has triggered an event.  This is commonly caused when a node sends a Basic_Set command to the controller.  The event value is stored in the notification.</summary>
		NodeEvent = Notification::Type_NodeEvent,
		/// <summary></summary>
		PollingDisabled = Notification::Type_PollingDisabled,
		/// <summary></summary>
		PollingEnabled = Notification::Type_PollingEnabled,
		/// <summary></summary>
		SceneEvent = Notification::Type_SceneEvent,
		/// <summary></summary>
		CreateButton = Notification::Type_CreateButton,
		/// <summary></summary>
		DeleteButton = Notification::Type_DeleteButton,
		/// <summary></summary>
		ButtonOn = Notification::Type_ButtonOn,
		/// <summary></summary>
		ButtonOff = Notification::Type_ButtonOff,
		/// <summary>A driver for a PC Z-Wave controller has been added and is ready to use.  The notification will contain the controller's Home ID, which is needed to call most of the Manager methods.</summary>
		DriverReady = Notification::Type_DriverReady,
		/// <summary>Driver failed to load</summary>
		DriverFailed = Notification::Type_DriverFailed,
		/// <summary>All nodes and values for this driver have been removed.  This is sent instead of potentially hundreds of individual node and value notifications.</summary>
		DriverReset = Notification::Type_DriverReset,
		/// <summary>The queries on a node that are essential to its operation have been completed. The node can now handle incoming messages.</summary>
		EssentialNodeQueriesComplete = Notification::Type_EssentialNodeQueriesComplete,
		/// <summary>All the initialization queries on a node have been completed.</summary> 
		NodeQueriesComplete = Notification::Type_NodeQueriesComplete,
		/// <summary>All awake nodes have been queried, so client application can expected complete data for these nodes.</summary>
		AwakeNodesQueried = Notification::Type_AwakeNodesQueried,
		///<summary>All nodes have been queried but some dead nodes found.</summary> 
		AllNodesQueriedSomeDead = Notification::Type_AllNodesQueriedSomeDead,
		/// <summary>All nodes have been queried, so client application can expected complete data.</summary> 
		AllNodesQueried = Notification::Type_AllNodesQueried,
		/// <summary>An error has occurred that we need to report.</summary> 
		Notification = Notification::Type_Notification,
		/// <summary>The Driver is being removed. (either due to Error or by request) Do Not Call Any Driver Related Methods after receiving this call</summary>
		DriverRemoved = Notification::Type_DriverRemoved,
		/// <summary>When Controller Commands are executed, Notifications of Success/Failure etc are communicated via this Notification</summary>
		ControllerCommand = Notification::Type_ControllerCommand,
		/// <summary>The Device has been reset and thus removed from the NodeList in OZW</summary>
		NodeReset = Notification::Type_NodeReset,
		/// <summary>Warnings and Notifications Generated by the library that should be displayed to the user (eg, out of date config files) </summary>
		UserAlerts = Notification::Type_UserAlerts,
		/// <summary>The ManufacturerSpecific Database Is Ready</summary>
		ManufacturerSpecificDBReady = Notification::Type_ManufacturerSpecificDBReady
	};

	/**
	* <summary>Notification codes.</summary>
	* <remarks>Notifications of the type Type_Notification convey some
	* extra information defined here.</remarks>
	*/
	public enum class ZWNotificationCode
	{
		/// <summary>Completed messages</summary>
		MsgComplete = Notification::Code_MsgComplete,
		/// <summary>Messages that timeout will send a Notification with this code.</summary> 
		Timeout = Notification::Code_Timeout,
		/// <summary>Report on NoOperation message sent completion.</summary>
		NoOperation = Notification::Code_NoOperation,
		/// <summary>Report when a sleeping node wakes up.</summary>
		Awake = Notification::Code_Awake,
		/// <summary>Report when a node goes to sleep.</summary>
		Sleep = Notification::Code_Sleep,
		/// <summary>Report when a node is presumed dead.</summary>
		Dead = Notification::Code_Dead,
		/// <summary>Report when a node is revived.</summary>
		Alive = Notification::Code_Alive
	};

	/// <summary>The classification of a value to enable low level system or configuration parameters to be filtered
	/// by the application.</summary>
	public enum class ZWValueGenre
	{
		/// <summary>The 'level' as controlled by basic commands.  Usually duplicated by another command class.</summary>
		Basic = ValueID::ValueGenre_Basic,
		/// <summary>Basic values an ordinary user would be interested in.</summary>
		User = ValueID::ValueGenre_User,
		/// <summary>Device-specific configuration parameters.  These cannot be automatically discovered via Z-Wave, and are usually described in the user manual instead.</summary>
		Config = ValueID::ValueGenre_Config,
		/// <summary>Values of significance only to users who understand the Z-Wave protocol.</summary>
		System = ValueID::ValueGenre_System
	};

	/// <summary>The type of data represented by the value object.</summary>
	public enum class ZWValueType
	{
		/// <summary>Boolean, true or false</summary>
		Bool = ValueID::ValueType_Bool,
		/// <summary>8-bit unsigned value</summary>
		Byte = ValueID::ValueType_Byte,
		/// <summary>Represents a non-integer value as a string, to avoid floating point accuracy issues.</summary>
		Decimal = ValueID::ValueType_Decimal,
		/// <summary>32-bit signed value</summary>
		Int = ValueID::ValueType_Int,
		/// <summary>List from which one item can be selected</summary>
		List = ValueID::ValueType_List,
		/// <summary>Complex type used with the Climate Control Schedule command class</summary>
		Schedule = ValueID::ValueType_Schedule,
		/// <summary>16-bit signed value</summary>
		Short = ValueID::ValueType_Short,
		/// <summary>Text string></summary>
		String = ValueID::ValueType_String,
		/// <summary>A write-only value that is the equivalent of pressing a button to send a command to a device</summary>
		Button = ValueID::ValueType_Button,
		/// <summary>A collection of bytes</summary>
		Raw = ValueID::ValueType_Raw
	};
};