#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#include "MainComponent.h"
#include "Utils.h"

PageStackComponent &getMainStack();

class PokeLaunchApplication : public JUCEApplication {
public:
  PokeLaunchApplication();

  const String getApplicationName() override;
  const String getApplicationVersion() override;
  bool moreThanOneInstanceAllowed() override;

  void initialise(const String &commandLine) override;
  void shutdown() override;

  void systemRequestedQuit() override;
  void anotherInstanceStarted(const String &commandLine) override;

  PageStackComponent &getMainStack();

  class MainWindow : public DocumentWindow {
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainWindow)

  public:
    MainWindow(String name, const var &configJson);

    void closeButtonPressed() override;
  };

private:
  ScopedPointer<MainWindow> mainWindow;
};
