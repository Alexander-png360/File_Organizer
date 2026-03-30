#include "app.h"
#include "MainFrame.h"
#include <filesystem>

namespace FileManager {

    void SortFilesByExtension(folderPath)
    {
        namespace fs = std::filesystem;
        //fs::path parent(parentFolder.ToStdWstring());
        fs::path parent(folderPath());

        if (!fs::exists(parent) || !fs::is_directory(parent))
            return;

        for (auto& entry : fs::recursive_directory_iterator(parent))
        {
            if (fs::is_regular_file(entry))
            {
                fs::path filePath = entry.path();
                std::wstring ext = filePath.extension().wstring();

                if (ext.empty())
                    ext = L"no_extension";

                fs::path targetFolder = parent / ext;
                fs::create_directories(targetFolder);

                fs::path targetPath = targetFolder / filePath.filename();
                fs::rename(filePath, targetPath);
            }
        }
    }

}

bool MyApp::OnInit()
{
    mainFrame* frame = new mainFrame("File Organizer");
    frame->Show(true);
    return true;
}


wxIMPLEMENT_APP(MyApp);
