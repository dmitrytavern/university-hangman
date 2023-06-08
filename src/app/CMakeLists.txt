set(PROJECT_SOURCES
  main.cpp
  mainwindow.cpp
)

qt_add_executable(Hangman
  MANUAL_FINALIZATION  
  ${PROJECT_SOURCES}
)

qt_add_resources(Hangman "app_images"
    PREFIX "/"
    FILES
        ../../resources/BGGameStartWidget.png
        ../../resources/user.svg
        ../../resources/BerkshireSwash-Regular.ttf
        ../../resources/Montserrat-VariableFont_wght.ttf
        ../../resources/Hangman_1.svg
        ../../resources/Hangman_2.svg
        ../../resources/Hangman_3.svg
        ../../resources/Hangman_4.svg
        ../../resources/Hangman_5.svg
        ../../resources/Hangman_6.svg
        ../../resources/Hangman_7.svg
        ../../resources/Hangman_8.svg
        ../../resources/words-for-hangman.txt
        ../../resources/BigScull.svg
)

target_link_libraries(Hangman 
  PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
  HomeWidget
  AboutWidget
  GameWidget
  GameStartWidget
  GameOverWidget  
  ComponentStyle
  GameController
  WordRandomizer
)

set_target_properties(Hangman PROPERTIES
  MACOSX_BUNDLE TRUE
  WIN32_EXECUTABLE TRUE
)

install(TARGETS Hangman
  BUNDLE DESTINATION .
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_finalize_executable(Hangman)
