# Star Trek™: Armada II (2001) Widescreen Resolution Patch
## STA2WidescreenPatch
__STA2WidescreenPatch__ is an .ASI patch for [Star Trek™: Armada II (2001)](https://en.wikipedia.org/wiki/Star_Trek:_Armada_II) which automatically expands resolution support to include your monitor's current resolution which is not supported by the original game. This patch works with all versions of the game, including the demo.

__STA2WidescreenPatch__ automatically replaces the `1280x960` resolution option in the game's Graphic Settings menu with the current resolution of your Windows desktop. For example, if you are using a `1920x1080` resolution monitor, `1920x1080` will be listed as a selectable resolution in the Graphics Settings menu in place of `1280x960`.

__STA2WidescreenPatch__ was created with the intent to add support for modern widescreen resolutions, though a nice side effect is that _any_ arbitrary resolution supported by your monitor will be available to the game. For example, `1152x864`, which is not supported by the original game, is now available to use when __STA2WidescreenPatch__ is installed.

This patch has been tested with about one hour of "Instant Action" gameplay and by completing the first Federation campaign mission "Invasion" at `1920x1080` (1080p) and `3840x2160` (4K) resolutions. Extensive testing (i.e. by playing through the entire single-player campaign) has not been done at the time of writing. It is unknown how this patch behaves with multiple-monitor configurations. If you encounter problems during gameplay, please report an issue on GitHub.

Screenshot at 1080p resolution:

![sta2-1080p](https://user-images.githubusercontent.com/13472038/231906318-446304c5-f0f9-4dbb-94eb-c556831fc421.png)

# Installation

* Install the latest [Visual C++ 2015 - 2022 (X86) Redistributable](https://aka.ms/vs/17/release/vc_redist.x86.exe), if not already installed on your system.
* Download `STA2WidescreenPatch.zip`.
* Extract the ZIP file and copy all contents to the root of the Star Trek™: Armada II game directory.
* Launch the game and go to the __Graphics Options__ menu. Select your monitor's native resolution from the dropdown list.
* Play the game!

## More complex configurations

### Windows XP users

* Install the __Microsoft Visual C++ Redistributable Package 2019 14.28.29914.0 (32-bit)__, if not already installed on your system.
    - This is the final version of the Microsoft Visual C++ Redistributable which supports Windows XP.
* Download `XP-STA2WidescreenPatch.zip`.
* Extract the ZIP file and copy all contents to the root of the Star Trek™: Armada II game directory.
* Launch the game and go to the __Graphics Options__ menu. Select your monitor's native resolution from the dropdown list.
* Play the game!

### Proper configuration of Patch Project 1.2.5 + STA2WidescreenPatch + dxwrapper or any other DirectX wrapper

[Patch Project 1.2.5](http://armadafiles.com/files/armada-2/mods/patches/star-trek-armada-ii-patch-project-zip-125/details) uses [madCodeHook](http://www.madshi.net/madCodeHookDescription.htm) to hook its DLLs into the game, and this prevents other DLL wrappers from functioning. To work around this issue, __STA2WidescreenPatch__ utilizes ThirteenAG's [Ultimate ASI Loader project](https://github.com/ThirteenAG/Ultimate-ASI-Loader) for seamless operation when Patch Project 1.2.5 is installed. No action is necessary when utilizing Patch Project 1.2.5 with __STA2WidescreenPatch__.

To utilize Patch Project 1.2.5 and __STA2WidescreenPatch__ along with any other DirectX wrapper such as [dxwrapper by elishacloud](https://github.com/elishacloud/dxwrapper/wiki/Star-Trek-Armada-1), you must rename your DirectX wrapper's __.DLL__ file to a __.ASI__ file and delete the bundled stub (e.g. __ddraw.dll__). For example, when using dxwrapper, __dxwrapper.dll__ must be renamed to __dxwrapper.asi__, and as a side effect, the bundled __ddraw.dll__ stub becomes redundant and can be safely deleted, because the wrapper is now being loaded by the ASI loader. Use of a DirectX wrapper is optional and is __not__ required for __STA2WidescreenPatch__ to work.

### Using version 1.0, 1.1, or GOG.com + STA2WidescreenPatch + dxwrapper or any other DirectX wrapper

Using any other non-1.2.5 version of Star Trek™: Armada II with __STA2WidescreenPatch__ and any DirectX wrapper should work without any further action. Use __ddraw.dll__ as the stub for the DirectX wrapper, because __winmm.dll__ is being used by the Ultimate ASI Loader to load __STA2WidescreenPatch__.

# Uninstallation

If you wish to undo this patch, simply delete the __STA2WidescreenPatch.asi__ and __winmm.dll__ files from your Star Trek™: Armada II game directory.

# Game Version Compatibility

| Game Version                                                                                                                                                                           | Compatible? |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------|
| [Demo](http://armadafiles.com/files/armada-2/official-releases/demo/star-trek-armada-ii-demo/details)                                                                                  | Yes         |
| Version 1.0                                                                                                                                                                            | Yes         |
| [Version 1.1](http://armadafiles.com/files/armada-2/official-releases/patches/star-trek-armada-ii-patch-11/details)                                                                    | Yes         |
| [GOG.com](https://www.gog.com/en/game/star_trek_armada_ii)                                                                                                                             | Yes         |
| [Patch Project 1.2.5](http://armadafiles.com/files/armada-2/mods/patches/star-trek-armada-ii-patch-project-zip-125/details)                                                            | Yes         |
| Any compatible version with a DirectX wrapper, e.g. [dxwrapper](https://github.com/elishacloud/dxwrapper/wiki/Star-Trek-Armada-1) or [d3d8to9](https://github.com/crosire/d3d8to9)     | Yes         |

# Operating System Compatibility

__STA2WidescreenPatch__ is compatible with Windows XP Service Pack 3 and later. Compatibility under Wine has not been tested by the developer.

# Known Issues

A few minor user interface related issues have been noticed so far:

- The loading screen image does not stretch to fill the screen, but this looks acceptable because a background image fills the rest of the screen.
- There are thin transparent gaps seen in the background of the __Mission Objectives__ screen.
- When an in-game cutscene plays in the cinematic window at the bottom right, it does not properly fill the entire window.

It is expected that minor interface glitches will occur as a result of using this resolution patch. It is not within the scope of this project to correct such issues. It is possible that a modder may be able to correct these issues by adjusting certain interface elements in the game files.

If you experience an issue that seems to be caused by __STA2WidescreenPatch__, or discover an incompatibility, please report an issue on GitHub.

Please note that menu glitchiness (lack of animation, mostly-black screen) is a pre-existing issue, seemingly affecting the GOG.com version the worst, and is not caused by __STA2WidescreenPatch__. It may be possible to utilize the [dxwrapper project by elishacloud](https://github.com/elishacloud/dxwrapper/wiki/Star-Trek-Armada-1) to correct this issue, but as this issue does not occur with the developer's system, utilizing dxwrapper to try to resolve this issue has not been attempted.

# Inspiration and Credits
This patch was inspired by and made possible thanks to [jeFF0Falltrades](https://github.com/jeFF0Falltrades)'s excellent video tutorial and Python script for patching the original Roller Coaster Tycoon (1999):

- YouTube: [Reverse Engineering/Game Patching Tutorial: Full Res Roller Coaster Tycoon with Ghidra+x64dbg+Python](https://youtu.be/cwBoUuy4nGc)
- GitHub: [Roller Coaster Tycoon (1999) Full Resolution Game Patch (with Video Tutorial)](https://github.com/jeFF0Falltrades/Tutorials/tree/master/rct_full_res)

It is also extremely helpful that `Armada2.pdb` was shipped with Star Trek™: Armada II patch 1.1, enabling much more human-readable decompilation.

Compatibility across combinations of DirectX wrappers and all versions of Star Trek™: Armada II is possible thanks to ThirteenAG's [Ultimate ASI Loader](https://github.com/ThirteenAG/Ultimate-ASI-Loader) project. A compiled version of the x86 version of Ultimate ASI Loader is bundled with this patch, renamed as `winmm.dll`. Please see `UltimateASILoader-license.txt` for license information.

[ChatGPT](https://openai.com/blog/chatgpt) was used to generate the majority of the C++ code used in this patch, so if something's kinda kludgy, blame ChatGPT and not me. Other tools used include [Ghidra](https://github.com/NationalSecurityAgency/ghidra) and [x64dbg](https://x64dbg.com/).

# Development

__STA2WidescreenPatch.asi__ (which is just a renamed DLL) is written in C++ using [Microsoft Visual Studio 2022 Community](https://visualstudio.microsoft.com/vs/community/) and requires the Windows 10 SDK. A Visual Studio 2022 solution is provided in the `source` folder in the GitHub repository, and the Windows XP compatible solution is in `source-xp`. The output file is appropriately named __STA2WidescreenPatch.asi__ and requires ThirteenAG's [Ultimate ASI Loader](https://github.com/ThirteenAG/Ultimate-ASI-Loader) to function, unless you decide to use another method of loading the DLL. The Windows XP release of __STA2WidescreenPatch__ uses [xan1242's XP-compatible fork of Ultimate ASI Loader](https://github.com/xan1242/Ultimate-ASI-Loader).

For the Windows XP solution, you must configure your Visual Studio installation according to [Configuring Programs for Windows XP](https://learn.microsoft.com/en-us/cpp/build/configuring-programs-for-windows-xp?view=msvc-170). [Stack Overflow: How to compile C++ app for Windows XP in MSVS?](https://stackoverflow.com/a/70285486) may be of help as well.

Thanks for stopping by, and enjoy playing Star Trek™: Armada II in glorious modern resolutions! To quote General Martok, "I thirst for battle!"
