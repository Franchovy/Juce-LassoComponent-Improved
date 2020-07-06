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

    void mouseDown(const MouseEvent &event) override;
    void mouseDrag(const MouseEvent &event) override;
    void mouseUp(const MouseEvent &event) override;

    //==============================================================================
    void addNewTestComponent();

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
    // Array of Components to run tests on
    OwnedArray<Component> testComponents;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
