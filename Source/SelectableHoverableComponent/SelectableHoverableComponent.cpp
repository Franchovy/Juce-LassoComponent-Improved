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
    auto outline = getLocalBounds();

    // Drawable outline based on selected or hovered
    g.setColour(Colours::blue);

    if (selected) {
        g.drawRect(outline, 4);

    } else if (hovered) {
        Path p;
        p.addRectangle(outline);

        PathStrokeType strokeType(4);
        float dashLengths[2] = {8.0f, 6.0f};
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
    if (event.mods.isShiftDown() || event.mods.isCtrlDown() || event.mods.isCommandDown()) {
        if (selected) {
            removeFromSelected();
        } else {
            addToSelected();
        }
    } else {
        clearSelected();
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

void SelectableHoverableComponent::clearSelected() {
    auto removableCopy = selectedComponents;
    for (auto item : removableCopy) {
        item->removeFromSelected();
        item->repaint();
    }
}


