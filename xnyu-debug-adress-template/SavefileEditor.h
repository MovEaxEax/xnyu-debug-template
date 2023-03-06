#pragma once

struct SavefileField {
    std::string nameParent;
    std::string nameChild;
    std::string nameFull;
    Variable value;
};

struct SavefileParent {
    std::string nameParent;
    std::vector<SavefileField> fields;
};




EXTERN_DLL_EXPORT void GetSavefiles(char* saveFiles)
{
    //
    // This function returns identifier for all the available savefiles
    //

    std::string directory = "";

    std::string files = "";

    for (const auto& _file : std::filesystem::directory_iterator(directory))
    {
        std::string finding = _file.path().filename().string();
        if (finding.find(".sav") != std::string::npos)
        {
            files = files + finding + ";";
        }
    }

    if (files.length() > 0)
    {
        files = files.substr(0, files.length() - 1);
        std::memcpy(saveFiles, files.c_str(), files.length());
        char term = 0x00;
        std::memcpy(saveFiles + files.length(), &term, 1);
    }
}

EXTERN_DLL_EXPORT void ScopeSavefile(std::string filename)
{

    //
    // before savefile data get's manipulated, the scoped file get's selected
    // 

}

EXTERN_DLL_EXPORT void LoadSavefile(SavefileParent* savefileParent)
{

    //
    // This function returns the current data of the savefile
    // It can be called multiple times, after reloading
    // 

}

EXTERN_DLL_EXPORT void SaveSavefile(SavefileParent* savefileParent)
{

    //
    // This function takes the new savefile data from a single parent and saves it
    // 

}


