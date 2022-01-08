
function(createSTDModules binDirectory)
if(UNIX AND NOT APPLE)
	execute_process(
		COMMAND ${CMAKE_SOURCE_DIR}/tool/create_g++_std_module.sh iostream ${CMAKE_CXX_COMPILER}
		COMMAND ${CMAKE_SOURCE_DIR}/tool/create_g++_std_module.sh memory ${CMAKE_CXX_COMPILER}
		COMMAND ${CMAKE_SOURCE_DIR}/tool/create_g++_std_module.sh string ${CMAKE_CXX_COMPILER}
		COMMAND ${CMAKE_SOURCE_DIR}/tool/create_g++_std_module.sh map ${CMAKE_CXX_COMPILER}
		COMMAND ${CMAKE_SOURCE_DIR}/tool/create_g++_std_module.sh vector ${CMAKE_CXX_COMPILER}
		COMMAND ${CMAKE_SOURCE_DIR}/tool/create_g++_std_module.sh set ${CMAKE_CXX_COMPILER}
		COMMAND ${CMAKE_SOURCE_DIR}/tool/create_g++_std_module.sh unordered_map ${CMAKE_CXX_COMPILER}
		COMMAND ${CMAKE_SOURCE_DIR}/tool/create_g++_std_module.sh initializer_list ${CMAKE_CXX_COMPILER}
		COMMAND ${CMAKE_SOURCE_DIR}/tool/create_g++_std_module.sh ranges ${CMAKE_CXX_COMPILER}
		COMMAND ${CMAKE_SOURCE_DIR}/tool/create_g++_std_module.sh coroutine ${CMAKE_CXX_COMPILER}
		COMMAND ${CMAKE_SOURCE_DIR}/tool/create_g++_std_module.sh optional ${CMAKE_CXX_COMPILER}
		COMMAND ${CMAKE_SOURCE_DIR}/tool/create_g++_std_module.sh source_location ${CMAKE_CXX_COMPILER}
		WORKING_DIRECTORY ${binDirectory}
		)
endif()
endfunction()

function(createSTDModule binDirectory STDModule)
if(UNIX AND NOT APPLE)
	execute_process(
		COMMAND ${CMAKE_SOURCE_DIR}/tool/create_g++_std_module.sh ${STDModule} ${CMAKE_CXX_COMPILER}
		WORKING_DIRECTORY ${binDirectory}
		)
endif()
endfunction()

