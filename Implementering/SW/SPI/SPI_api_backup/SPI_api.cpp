   HintAuto b            HintName s            HintIconName s                HintSymbolicIconName s       on="in"/>
      <arg type="s" name="property_name" direction="in"/>
      <arg type="v" name="value" direction="in"/>
    </method>
    <signal name="PropertiesChanged">
      <arg type="s" name="interface_name"/>
      <arg type="a{sv}" name="changed_properties"/>
      <arg type="as" name="invalidated_properties"/>
    </signal>
  </interface>
  <interface name="org.freedesktop.DBus.Introspectable">
    <method name="Introspect">
      <arg type="s" name="xml_data" direction="out"/>
    </method>
  </interface>
  <interface name="org.freedesktop.DBus.Peer">
    <method name="Ping"/>
    <method name="GetMachineId">
      <arg type="s" name="machine_uuid" direction="out"/>
    </method>
  </interface>
  <interface name="org.freedesktop.UDisks2.Block">
    <method name="AddConfigurationItem">
      <arg type="(sa{sv})" name="item" direction="in"/>
      <arg type="a{sv}" name="options" direction="in"/>
    </method>
    <method name="RemoveConfigurationItem">
      <arg type="(sa{sv})" name="item" direction="in"/>
      <arg type="a{sv}" name="options" direction="in"/>
    </method>
    <method name="UpdateConfigurationItem">
      <arg type="(sa{sv})" name="old_item" direction="in"/>
      <arg type="(sa{sv})" name="new_item" direction="in"/>
      <arg type="a{sv}" name="options" direction="in"/>
    </method>
    <method name="GetSecretConfiguration">
      <arg type="a{sv}" name="options" direction="in"/>
      <arg type="a(sa{sv})" name="configuration" direction="out"/>
    </method>
    <method name="Format">
      <arg type="s" name="type" direction="in"/>
      <arg type="a{sv}" name="options" direction="in"/>
    </method>
    <method name="OpenForBackup">
      <arg type="a{sv}" name="options" direction="in"/>
      <arg type="h" name="fd" direction="out"/>
    </method>
    <method name="OpenForRestore">
      <arg type="a{sv}" name="options" direction="in"/>
      <arg type="h" name="fd" direction="out"/>
    </method>
    <method name="OpenForBenchmark">
      <arg type="a{sv}" name="options" direction="in"/>
      <arg type="h" name="fd" direction="out"/>
    </method>
    <method name="Rescan">
      <arg type="a{sv}" name="options" direction="in"/>
    </method>
    <property type="ay" name="Device" access="read"/>
    <property type="ay" name="PreferredDevice" access="read"/>
    <property type="aay" name="Symlinks" access="read"/>
    <property type="t" name="DeviceNumber" access="read"/>
    <property type="s" name="Id" access="read"/>
    <property type="t" name="Size" access="read"/>
    <property type="b" name="ReadOnly" access="read"/>
    <property type="o" name="Drive" access="read"/>
    <property type="o" name="MDRaid" access="read"/>
    <property type="o" name="MDRaidMember" access="read"/>
    <property type="s" name="IdUsage" access="read"/>
    <property type="s" name="IdType" access="read"/>
    <property type="s" name="IdVersion" access="read"/>
    <property type="s" name="IdLabel" access="read"/>
    <property type="s" name="IdUUID" access="read"/>
    <property type="a(sa{sv})" name="Configuration" access="read"/>
    <property type="o" name="CryptoBackingDevice" access="read"/>
    <property type="b" name="HintPartitionable" access="read"/>
    <property type="b" name="HintSystem" access="read"/>
    <property type="b" name="HintIgnore" access="read"/>
    <property type="b" name="HintAuto" access="read"/>
    <property type="s" name="HintName" access="read"/>
    <property type="s" name="HintIconName" access="read"/>
    <property type="s" name="HintSymbolicIconName" access="read"/>
  </interface>
</node>
  �	AddConfi�  8   ���	      ���	`rP r e f e r r e d D e v i c e     )   x��	`c�	                  �:     �98�x �	�t�	       a  p�	`Wr�p�	���	ce ay     /dev/ram12     PreferredDevice ay    /dev/ram12     Symlinks aay          DeviceNumber t              Id s                  Size t               ReadOnly b            Drive o       /      MDRaid o      /      MDRaidMember o    /          IdUsage s             IdType s           	   IdVersion s                   IdLabel s             IdUUID s              Configuration 	a(sa{sv})               CryptoBackingDevice o     /          HintPartitionable b       
   HintSystem b      
   HintIgnore b          HintAuto b            HintName s            HintIconName s                HintSymbolicIconName s       on="in"/>
      <arg type="s" name="property_name" direction="in"/>
      <arg type="v" name="value" direction="in"/>
    </method>
    <signal name="PropertiesChanged">
      <arg type="s" name="interface_name"/>
      <arg type="a{sv}" name="changed_properties"/>
      <arg type="as" name="invalidated_properties"/>
    </signal>
  </interface>
  <interface name="org.freedesktop.DBus.Introspectable">
    <method name="Introspect">
      <arg type="s" name="xml_data" direction="out"/>
    </method>
  </interface>
  <interface name="org.freedesktop.DBus.Peer">
    <method name="Ping"/>
    <method name="GetMachineId">
      <arg type="s" name="machine_uuid" direction="out"/>
    </method>
  </interface>
  <interface name="org.freedesktop.UDisks2.Block">
    <method name="AddConfigurationItem">
      <arg type="(sa{sv})" name="item" direction="in"/>
      <arg type="a{sv}" name="options" direction="in"/>
    </method>
    <method name="RemoveConfigurationItem">
      <arg type="(sa{sv})" name="item" direction="in"/>
      <arg type="a{sv}" name="options" direction="in"/>
    </method>
    <method name="UpdateConfigurationItem">
      <arg type="(sa{sv})" name="old_item" direction="in"/>
      <arg type="(sa{sv})" name="new_item" direction="in"/>
      <arg type="a{sv}" name="options" direction="in"/>
    </method>
    <method name="GetSecretConfiguration">
      <arg type="a{sv}" name="options" direction="in"/>
      <arg type="a(s