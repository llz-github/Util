set DEP_SRC_DIR=%cd%
set QT5_DIR=%ThirdPart%\Qt5.11\vc140\x64
set ThirdPart=%ThirdPart%
set BUILD_XSIM_PRODUCT=1
mkdir Build_DEBUG
cd Build_DEBUG
cmake -G "Visual Studio 15 2017 Win64" -DCMAKE_BUILD_TYPE=DEBUG ../
pause
