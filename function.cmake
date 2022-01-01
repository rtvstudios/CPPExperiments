
function(createSTDModules binDirectory)
if(UNIX AND NOT APPLE)
	execute_process(
		COMMAND ${CMAKE_CXX_COMPILER} -std=c++20 -fmodules-ts -xc++-system-header iostream
		COMMAND ${CMAKE_CXX_COMPILER} -std=c++20 -fmodules-ts -xc++-system-header memory
		COMMAND ${CMAKE_CXX_COMPILER} -std=c++20 -fmodules-ts -xc++-system-header string
		COMMAND ${CMAKE_CXX_COMPILER} -std=c++20 -fmodules-ts -xc++-system-header map
		COMMAND ${CMAKE_CXX_COMPILER} -std=c++20 -fmodules-ts -xc++-system-header vector
		COMMAND ${CMAKE_CXX_COMPILER} -std=c++20 -fmodules-ts -xc++-system-header set
		COMMAND ${CMAKE_CXX_COMPILER} -std=c++20 -fmodules-ts -xc++-system-header unordered_map
		COMMAND ${CMAKE_CXX_COMPILER} -std=c++20 -fmodules-ts -xc++-system-header initializer_list
		COMMAND ${CMAKE_CXX_COMPILER} -std=c++20 -fmodules-ts -xc++-system-header ranges
		WORKING_DIRECTORY ${binDirectory}
		)
endif()
endfunction()

function(createSTDModule binDirectory STDModule)
if(UNIX AND NOT APPLE)
	execute_process(
		COMMAND ${CMAKE_CXX_COMPILER} -std=c++20 -fmodules-ts -xc++-system-header iostream ${STDModule}
		WORKING_DIRECTORY ${binDirectory}
		)
endif()
endfunction()

