Ubpa_DownloadFile(
	https://ubpa.github.io/UData/UBL/LTCTex.h
	${CMAKE_CURRENT_SOURCE_DIR}/_deps/LTCTex.h
	SHA256 97440180027741FBA936DC08BB6757710A496D45B8EAE4B062076DDB0C659367)

Ubpa_GlobGroupSrcs(RST sources PATHS
	${CMAKE_CURRENT_SOURCE_DIR}
	"${PROJECT_SOURCE_DIR}/include/URTR"
)

Ubpa_AddTarget_GDR(
	MODE "LIB"
	SOURCES ${sources}
	INTERFACE_INC ON
	PUBLIC_GLIBS
		"Ubpa::UScene_core"
		"Ubpa::UScene_tool"
		"Ubpa::UGL_core"
		"Ubpa::UDP_core"
)
