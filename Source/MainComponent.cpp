/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include "TestComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Set Screen Bounds
    auto screenBounds = Desktop::getInstance().getDisplays().getTotalBounds(true);
    setBounds(screenBounds);

    // Random to scatter test components
    Random r;

    auto numTestComponents = r.nextInt(Range<int>(20, 80));
    for (int i = 0; i < numTestComponents; i++) {
        auto component = testComponents.add(std::make_unique<TestComponent>());
        component->setBounds(r.nextInt(getWidth() - 300), r.nextInt(getHeight() - 300)
                , r.nextInt(Range<int>(100, 300)), r.nextInt(Range<int>(100,300)));

        addAndMakeVisible(component);
    }

    addChildComponent(lasso);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    Component::paint(g);
}

void MainComponent::resized()
{
    Component::resized();
}

void MainComponent::mouseDown(const MouseEvent &event) {
    lasso.setVisible(true);
    lasso.beginLasso(event, this);
    Component::mouseDown(event);
}

void MainComponent::mouseDrag(const MouseEvent &event) {
    lasso.dragLasso(event);
    Component::mouseDrag(event);
}

void MainComponent::mouseUp(const MouseEvent &event) {
    lasso.endLasso();
    Component::mouseUp(event);
}
