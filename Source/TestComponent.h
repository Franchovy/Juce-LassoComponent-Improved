/*
  ==============================================================================

    TestComponent.h
    Created: 6 Jul 2020 4:37:27pm
    Author:  maxime

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SelectableHoverableComponent.h"

class TestComponent : public SelectableHoverableComponent
{
public:
    TestComponent() = default;

    void paint(Graphics &g) override;


private:

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TestComponent)
};