cmake_minimum_required(VERSION 3.1.0)
project(StandardProject)
include(module_standard.cmake)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

IF(CMAKE_SYSTEM_NAME MATCHES "Windows")
	IF(PLATFORM MATCHES x64)
		add_subdirectory(Util)
		add_subdirectory(DeviceStatusMonitoring)
		add_subdirectory(UDPGateWay)
		add_subdirectory(HeartBeat)
		add_subdirectory(OperateFileTools)

		set(Dependency Util)

		add_dependencies(DeviceStatusMonitoring ${Dependency})
		add_dependencies(UDPGateWay ${Dependency})
		add_dependencies(HeartBeat ${Dependency})
	ENDIF()
ENDIF()


set_target_properties(Util PROPERTIES FOLDER Util)
set_target_properties(OperateFileTools PROPERTIES FOLDER Extral)

set_target_properties(DeviceStatusMonitoring PROPERTIES FOLDER Exe)
set_target_properties(UDPGateWay PROPERTIES FOLDER Exe)
set_target_properties(HeartBeat PROPERTIES FOLDER Exe)
