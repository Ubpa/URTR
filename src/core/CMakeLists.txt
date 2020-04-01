Ubpa_GlobGroupSrcs(RST sources PATHS
	${CMAKE_CURRENT_SOURCE_DIR}
	"${PROJECT_SOURCE_DIR}/include/URTR"
)

if(${UBPA_UGL_GLAD})
	add_definitions(-DUBPA_UGL_GLAD)
endif()

Ubpa_AddTarget_GDR(
	MODE "LIB"
	SOURCES ${sources}
	INTERFACE_INC ON
	GENERAL_LIBS
		"Ubpa::UScene_core"
	PUBLIC_GLIBS
		"Ubpa::UGL_core"
)
