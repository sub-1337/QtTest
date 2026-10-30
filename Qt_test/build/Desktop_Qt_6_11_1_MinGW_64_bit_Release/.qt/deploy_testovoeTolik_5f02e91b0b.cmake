include("C:/Users/subli/Local/Git/anatolyTest/Qt_test/build/Desktop_Qt_6_11_1_MinGW_64_bit_Release/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/testovoeTolik-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE "C:/Users/subli/Local/Git/anatolyTest/Qt_test/build/Desktop_Qt_6_11_1_MinGW_64_bit_Release/testovoeTolik.exe"
    GENERATE_QT_CONF
)
