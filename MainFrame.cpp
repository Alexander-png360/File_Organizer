#include "MainFrame.h"
#include "App.h"

mainFrame::mainFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(500, 350))
{
    wxPanel* panel = new wxPanel(this);

    descriptionLabel = new wxStaticText(
        panel,
        wxID_ANY,
        "Select a folder and click Sort to organize files by extension",
        wxPoint(20, 10),
        wxSize(450, 20)
    );

    // Folder selection
    selectFolderButton = new wxButton(
        panel,
        wxID_ANY,
        "Select Folder",
        wxPoint(20, 40),
        wxSize(150, 30)
    );

    folderLabel = new wxStaticText(
        panel,
        wxID_ANY,
        "No folder selected",
        wxPoint(20, 80),
        wxSize(450, 30)
    );

    // Generate / Sort button
    generateButton = new wxButton(
        panel,
        wxID_ANY,
        "Sort",
        wxPoint(20, 120),
        wxSize(150, 30)
    );

    // Progress bar
    progressBar = new wxGauge(
        panel,
        wxID_ANY,
        100,
        wxPoint(20, 160),
        wxSize(450, 25)
    );

    // Time remaining
    timeRemainingLabel = new wxStaticText(
        panel,
        wxID_ANY,
        "Time remaining: 0s",
        wxPoint(20, 200),
        wxSize(450, 30)
    );

    // Completed message
    completedLabel = new wxStaticText(
        panel,
        wxID_ANY,
        "",
        wxPoint(20, 240),
        wxSize(450, 30)
    );

    // Bind events
    Bind(wxEVT_BUTTON, &mainFrame::OnSelectFolder, this, selectFolderButton->GetId());
    Bind(wxEVT_BUTTON, &mainFrame::OnGenerateFiles, this, generateButton->GetId());
}

void mainFrame::OnSelectFolder(wxCommandEvent& evt)
{
    wxDirDialog dlg(this, "Choose a folder");

    if (dlg.ShowModal() == wxID_OK)
    {
        selectedFolder = dlg.GetPath();
        folderLabel->SetLabel(selectedFolder);
    }
}

void mainFrame::OnGenerateFiles(wxCommandEvent& evt)
{
    if (selectedFolder.IsEmpty())
    {
        wxMessageBox("Please select a folder first!", "Error", wxOK | wxICON_ERROR);
        return;
    }

    progressBar->SetValue(0);
    timeRemainingLabel->SetLabel("Time remaining: calculating...");
    completedLabel->SetLabel("");

    FileManager::SortFilesByExtension(selectedFolder);

    completedLabel->SetLabel("Sorting completed!");
    progressBar->SetValue(100);
    timeRemainingLabel->SetLabel("Time remaining: 0s");
}
