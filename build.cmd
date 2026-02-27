@echo off

if not exist packages (
  mkdir packages
  pushd packages
  echo Downloading nuget packages ...
  curl.exe -fLo Microsoft.WindowsAppSDK.nupkg                        https://www.nuget.org/api/v2/package/Microsoft.WindowsAppSDK/1.8.260209005                        || exit /b 1
  curl.exe -fLo Microsoft.WindowsAppSDK.Base.nupkg                   https://www.nuget.org/api/v2/package/Microsoft.WindowsAppSDK.Base/1.8.251216001                   || exit /b 1
  curl.exe -fLo Microsoft.WindowsAppSDK.Foundation.nupkg             https://www.nuget.org/api/v2/package/Microsoft.WindowsAppSDK.Foundation/1.8.260203002             || exit /b 1
  curl.exe -fLo Microsoft.WindowsAppSDK.InteractiveExperiences.nupkg https://www.nuget.org/api/v2/package/Microsoft.WindowsAppSDK.InteractiveExperiences/1.8.260125001 || exit /b 1
  curl.exe -fLo Microsoft.WindowsAppSDK.WinUI.nupkg                  https://www.nuget.org/api/v2/package/Microsoft.WindowsAppSDK.WinUI/1.8.260204000                  || exit /b 1
  curl.exe -fLo Microsoft.WindowsAppSDK.DWrite.nupkg                 https://www.nuget.org/api/v2/package/Microsoft.WindowsAppSDK.DWrite/1.8.25122902                  || exit /b 1
  curl.exe -fLo Microsoft.WindowsAppSDK.Widgets.nupkg                https://www.nuget.org/api/v2/package/Microsoft.WindowsAppSDK.Widgets/1.8.251231004                || exit /b 1
  curl.exe -fLo Microsoft.WindowsAppSDK.Runtime.nupkg                https://www.nuget.org/api/v2/package/Microsoft.WindowsAppSDK.Runtime/1.8.260209005                || exit /b 1
  rem curl.exe -fLo Microsoft.Windows.SDK.BuildTools.nupkg               https://www.nuget.org/api/v2/package/Microsoft.Windows.SDK.BuildTools/10.0.26100.7705             || exit /b 1
  rem curl.exe -fLo Microsoft.Windows.CppWinRT.nupkg                     https://www.nuget.org/api/v2/package/Microsoft.Windows.CppWinRT/2.0.250303.1                      || exit /b 1
  curl.exe -fLo Microsoft.Web.WebView2.nupkg                         https://www.nuget.org/api/v2/package/Microsoft.Web.WebView2/1.0.3800.47                           || exit /b 1
  echo Unpacking nuget packages ...
  for %%f in (*.nupkg) do tar.exe -xf %%f || exit /b 1
  popd
)

if not exist idl (
  echo Generating idl files ...
  winmdidl.exe /nologo /outdir:idl /metadata_dir:packages\metadata packages\metadata\Microsoft.UI.Xaml.winmd                 2>nul
  winmdidl.exe /nologo /outdir:idl /metadata_dir:packages\metadata packages\metadata\Microsoft.UI.Text.winmd                 2>nul
  winmdidl.exe /nologo /outdir:idl /metadata_dir:packages\metadata packages\metadata\10.0.18362.0\Microsoft.UI.winmd         2>nul
  winmdidl.exe /nologo /outdir:idl /metadata_dir:packages\metadata packages\metadata\10.0.18362.0\Microsoft.Foundation.winmd 2>nul
  winmdidl.exe /nologo /outdir:idl /metadata_dir:packages\metadata packages\metadata\10.0.18362.0\Microsoft.Graphics.winmd   2>nul
  winmdidl.exe /nologo /outdir:idl /metadata_dir:packages\metadata packages\lib\Microsoft.Web.WebView2.Core.winmd            2>nul
)

if not exist includes (
  echo Generating includes, this will take a while ...
  mkdir includes
  for %%f in (idl\*.idl) do midlrt.exe %%f /nologo /out includes /winrt /ns_prefix /nomd /I idl /I packages\include 2>nul

  rem idk how to generate this, but empty file works fine
  echo. >includes\Microsoft.Windows.ApplicationModel.Resources.h
)

if not exist output (
  mkdir output
  makepri.exe new /pr . /cf main.priconfig.xml /of output\main.pri /o
  copy /y packages\runtimes-framework\win-x64\native\CoreMessagingXP.dll                              output\ 1>nul
  copy /y packages\runtimes-framework\win-x64\native\dcompi.dll                                       output\ 1>nul
  copy /y packages\runtimes-framework\win-x64\native\dwmcorei.dll                                     output\ 1>nul
  copy /y packages\runtimes-framework\win-x64\native\main.exe                                         output\ 1>nul
  copy /y packages\runtimes-framework\win-x64\native\main.pri                                         output\ 1>nul
  copy /y packages\runtimes-framework\win-x64\native\marshal.dll                                      output\ 1>nul
  copy /y packages\runtimes-framework\win-x64\native\Microsoft.DirectManipulation.dll                 output\ 1>nul
  copy /y packages\runtimes-framework\win-x64\native\Microsoft.InputStateManager.dll                  output\ 1>nul
  copy /y packages\runtimes-framework\win-x64\native\Microsoft.Internal.FrameworkUdk.dll              output\ 1>nul
  copy /y packages\runtimes-framework\win-x64\native\Microsoft.UI.Composition.OSSupport.dll           output\ 1>nul
  copy /y packages\runtimes-framework\win-x64\native\Microsoft.UI.dll                                 output\ 1>nul
  copy /y packages\runtimes-framework\win-x64\native\Microsoft.UI.Input.dll                           output\ 1>nul
  copy /y packages\runtimes-framework\win-x64\native\Microsoft.UI.Windowing.Core.dll                  output\ 1>nul
  copy /y packages\runtimes-framework\win-x64\native\Microsoft.UI.Windowing.dll                       output\ 1>nul
  copy /y packages\runtimes-framework\win-x64\native\Microsoft.UI.Xaml.Controls.dll                   output\ 1>nul
  copy /y packages\runtimes-framework\win-x64\native\Microsoft.ui.xaml.dll                            output\ 1>nul
  copy /y packages\runtimes-framework\win-x64\native\Microsoft.ui.xaml.resources.19h1.dll             output\ 1>nul
  copy /y packages\runtimes-framework\win-x64\native\Microsoft.Windows.ApplicationModel.Resources.dll output\ 1>nul
  copy /y packages\runtimes-framework\win-x64\native\Microsoft.Windows.Widgets.dll                    output\ 1>nul
  copy /y packages\runtimes-framework\win-x64\native\Microsoft.WindowsAppRuntime.dll                  output\ 1>nul
  copy /y packages\runtimes-framework\win-x64\native\MRM.dll                                          output\ 1>nul
)

rem main.manifest is generated by C# code with GenerateAppManifestFromAppx step from packages\build\Microsoft.WindowsAppSDK.SelfContained.targets file
rem as input it uses AppxManifest.xml file from packages\tools\MSIX\win10-x64\Microsoft.WindowsAppRuntime.1.8.msix archive

cl.exe /nologo /Z7 /O2 /MT /W3 /Iincludes main.c /link /incremental:no /opt:ref /opt:icf /out:output\main.exe /manifest:embed /manifestinput:main.manifest /defaultlib:ucrt.lib /nodefaultlib:libucrt.lib
