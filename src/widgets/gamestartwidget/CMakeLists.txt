set(LIBRARY_NAME GameStartWidget)

add_library(${LIBRARY_NAME} STATIC
  gamestartwidget.cpp
)

target_link_libraries(${LIBRARY_NAME}
  PRIVATE Qt6::Widgets
)

set_target_properties(${LIBRARY_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
