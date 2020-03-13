/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component, LassoSource<Component*>
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    // Lasso variables and methods
    LassoComponent<Component*> lasso;

    SelectedItemSet<Component*> itemsSet;
    void findLassoItemsInArea(Array<Component*> &itemsFound, const Rectangle<int> &area) override {

    }

    SelectedItemSet<Component *> &getLassoSelection() override {
        // Create empty item set
        itemsSet = SelectedItemSet<Component*>();

        return itemsSet;
    }

    //==============================================================================
    // Components



    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
