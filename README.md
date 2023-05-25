# kismet-debugger
Proof of concept kismet debugger for debugging blueprints running in release builds of Unreal Engine games. Built as a mod for [UE4SS](https://github.com/UE4SS-RE/RE-UE4SS).

## building

```bash
# clone recursively
git clone https://github.com/trumank/kismet-debugger.git --recursive
cd kismet-debugger

# build with cmake & ninja
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```

## installing
1. Have a functional install of UE4SS with CPPSDK
2. Copy `./build/KismetDebugger.dll` to `<UE4SS install>/Mods/KismetDebugger/dlls/main.dll`
3. Enable by adding `KismetDebugger : 1` to `Mods/mods.txt`

## usage
So far it's not very useful. There is a rudamentary nav/search bar to explore functions and set breakpoints. The call stack and local variables can also be inspected. Otherwise, there are still a lot of missing features you would expect a debugger to have.

https://github.com/trumank/kismet-debugger/assets/1144160/12decb2b-24e5-4893-b82a-2a2360fdaf89