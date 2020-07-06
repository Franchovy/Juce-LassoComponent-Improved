/*
  ==============================================================================

    TestComponent.cpp
    Created: 6 Jul 2020 4:37:27pm
    Author:  maxime

  ==============================================================================
*/

#include "TestComponent.h"

void TestComponent::paint(Graphics &g) {
    g.setColour(Colours::whitesmoke);
    g.fillEllipse(getLocalBounds().expanded(-20).toFloat());

    SelectableHoverableComponent::paint(g);
}
