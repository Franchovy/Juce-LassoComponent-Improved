/*
  ==============================================================================

    SelectableHoverableComponent.h
    Created: 6 Jul 2020 3:54:39pm
    Author:  maxime

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SelectableHoverableComponent : public Component
{
public:
    SelectableHoverableComponent();
    ~SelectableHoverableComponent();

    //==============================================================================

    void mouseEnter(const MouseEvent &event) override;
    void mouseExit(const MouseEvent &event) override;

    void mouseDown(const MouseEvent &event) override;
    void mouseDrag(const MouseEvent &event) override;
    void mouseUp(const MouseEvent &event) override;

    //==============================================================================

    void paint(Graphics &g) override;

private:
    //==============================================================================
    bool hovered = false;
    bool selected = false;


    //==============================================================================
    // Static data and accompanying methods

    void addToSelected();
    void removeFromSelected();

    static Array<SelectableHoverableComponent*> selectedComponents;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SelectableHoverableComponent)
};