project(${BII_BLOCK_NAME})

include(azriel/sl_cmake/slBlockFunctions)
include(biicode/cmake/tools)

# Bii variables
set(BII_main_DEPS ${BII_main_DEPS}
                  azriel_cppmicroservices
                  azriel_sl_core_application
                  azriel_sl_ax_engine
                  azriel_sl_ax_main)

usFunctionGenerateModuleInit(BII_main_SRC MODULE_NAME ${BII_BLOCK_NAME})
usFunctionGetResourceSource(TARGET ${BII_BLOCK_USER}_${BII_BLOCK_NAME}_main OUT BII_main_SRC)

# Actually create targets: executables and libraries.
ADD_BII_TARGETS()

ACTIVATE_CPP11(${BII_main_TARGET})
ADAPT_TARGETS_FOR_CPPMICROSERVICES(${BII_main_TARGET})

usFunctionAddResources(TARGET ${BII_main_TARGET}
                       MODULE_NAME ${BII_BLOCK_NAME}
                       FILES manifest.json
                      )
usFunctionEmbedResources(TARGET ${BII_main_TARGET})
