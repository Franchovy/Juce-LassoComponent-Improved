/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SelectableHoverableComponent/SelectableHoverableComponent.h"
#include "LassoComponent/LassoSelector.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent : public Component, LassoSource<SelectableHoverableComponent*>
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


private:
    //==============================================================================
    // Lasso variables and methods
    LassoSelector<SelectableHoverableComponent*> lasso;

    SelectedItemSet<SelectableHoverableComponent*> itemsSet;
    void findLassoItemsInArea(Array<SelectableHoverableComponent*> &itemsFound, const Rectangle<int> &area) override {

    }

    SelectedItemSet<SelectableHoverableComponent *> &getLassoSelection() override {
        // Create empty item set
        itemsSet = SelectedItemSet<SelectableHoverableComponent*>();

        return itemsSet;
    }

    //==============================================================================
    // Array of Components to run tests on
    OwnedArray<Component> testComponents;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
