#pragma once
#include "wx/wx.h"

class mainFrame : public wxFrame
{
public:
    mainFrame(const wxString& title);

private:
    void OnSelectFolder(wxCommandEvent& evt);
    void OnGenerateFiles(wxCommandEvent& evt);

    // UI
    wxStaticText* descriptionLabel;
    wxButton* selectFolderButton;
    wxButton* generateButton;
    wxStaticText* folderLabel;
    wxGauge* progressBar;
    wxStaticText* timeRemainingLabel;
    wxStaticText* completedLabel;

    // Data
    wxString selectedFolder;
    wxString pendingFileName;
};
