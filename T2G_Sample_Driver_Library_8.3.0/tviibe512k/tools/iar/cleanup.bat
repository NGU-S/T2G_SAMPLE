
for %%m in (flash sram) do (
    
    rmdir /Q /S %%m\settings

    for %%c in (cm0plus cm0plus_cm4 cm4_mc) do (

		rmdir /Q /S %%m\%%c\rev_d
        rmdir /Q /S %%m\%%c\Release
        rmdir /Q /S %%m\%%c\settings
        rmdir /Q /S %%m\%%c\libcrypto\Obj
        rmdir /Q /S %%m\%%c\libcrypto\settings
        del   /Q    %%m\%%c\BuildLog.log
        del   /Q    %%m\%%c\*.dep
        del   /Q    %%m\%%c\libcrypto\BuildLog.log
        
    )
)
