#pragma once
#include <wx/wx.h>      // Needed for wxApp
#include <wx/string.h>  // Needed for wxString

// wxApp subclass declaration
class MyApp : public wxApp
{
public:
    virtual bool OnInit() override;  // declaration of OnInit
};

// FileManager function declaration
namespace FileManager {
    void SortFilesByExtension(const wxString& parentFolder);
}
