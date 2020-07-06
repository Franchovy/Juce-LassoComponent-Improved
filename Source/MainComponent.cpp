/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent() :
    combo("combo")
{
    // Set Screen Bounds
    auto screenBounds = Desktop::getInstance().getDisplays().getTotalBounds(true);
    setBounds(screenBounds);

    combo.addItem("test1",1);
    combo.addItem("test2",2);
    combo.addItem("test3",3);

    combo.setVisible(true);
    combo.addToDesktop(ComponentPeer::StyleFlags::windowHasTitleBar | ComponentPeer::StyleFlags::windowHasCloseButton);
    combo.setBounds(0,0,100,100);
    combo.setJustificationType(Justification::centred);



    auto& lnf = getLookAndFeel();
    lnf.getComboBoxFont(combo).setHeight(10);
    lnf.getComboBoxFont(combo).setItalic(true);
    combo.setLookAndFeel(&lnf);
    combo.lookAndFeelChanged();
    repaint();

    addChildComponent(lasso);
    setSize (getAppProperties() 600, 400);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    //combo.setBounds(getWidth()/2 - 100, getHeight()/2 - 20,200, 40);
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

void MainComponent::addNewTestComponent() {
    Random r;
    auto position = Point<int>(r.nextInt(getWidth()), r.nextInt(getHeight()));

    testComponents.add(std::make_unique<Component)
}

