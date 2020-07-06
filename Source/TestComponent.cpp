/*
  ==============================================================================

    TestComponent.cpp
    Created: 6 Jul 2020 4:37:27pm
    Author:  maxime

  ==============================================================================
*/

#include "TestComponent.h"

void TestComponent::paint(Graphics &g) {
    auto bounds = getLocalBounds().expanded(-20).toFloat();

    g.setColour(Colours::whitesmoke);
    g.fillEllipse(bounds);

    g.setColour(Colours::black);
    g.drawEllipse(bounds, 2);

    SelectableHoverableComponent::paint(g);
}
