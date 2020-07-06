/*
  ==============================================================================

    SelectableHoverableComponent.cpp
    Created: 6 Jul 2020 3:54:39pm
    Author:  maxime

  ==============================================================================
*/

#include "SelectableHoverableComponent.h"

Array<SelectableHoverableComponent*> SelectableHoverableComponent::selectedComponents;

SelectableHoverableComponent::SelectableHoverableComponent() {
    setRepaintsOnMouseActivity(true);
}

SelectableHoverableComponent::~SelectableHoverableComponent() {
    removeFromSelected();
}

void SelectableHoverableComponent::mouseEnter(const MouseEvent &event) {
    hovered = true;

    Component::mouseEnter(event);
}

void SelectableHoverableComponent::mouseExit(const MouseEvent &event) {
    hovered = false;

    Component::mouseExit(event);
}

void SelectableHoverableComponent::paint(Graphics &g) {
    auto outline = getBounds();
    
    // Drawable outline based on selected or hovered
    g.setColour(Colours::blue);

    if (selected) {
        g.drawRect(outline, 2);

    } else if (hovered) {
        Path p;
        p.addRectangle(outline);

        PathStrokeType strokeType(2);
        float dashLengths[2] = {2.0f, 3.0f};
        strokeType.createDashedStroke(p, p, dashLengths, 2);

        g.fillPath(p);
    }
    Component::paint(g);
}

void SelectableHoverableComponent::mouseDown(const MouseEvent &event) {
    Component::mouseDown(event);
}

void SelectableHoverableComponent::mouseDrag(const MouseEvent &event) {
    Component::mouseDrag(event);
}

void SelectableHoverableComponent::mouseUp(const MouseEvent &event) {
    if (selected) {
        removeFromSelected();
    } else {
        addToSelected();
    }

    Component::mouseUp(event);
}

void SelectableHoverableComponent::addToSelected() {
    selected = true;
    selectedComponents.add(this);
}

void SelectableHoverableComponent::removeFromSelected() {
    selected = false;
    selectedComponents.removeAllInstancesOf(this);
}


