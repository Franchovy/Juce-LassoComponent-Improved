# LassoComponentExample
Example use of JUCE LassoComponent, and LassoSource. I struggled to figure this class out at first.

I'm using this class in my private project, but thought I may put up and share an open version to help and to have contributors if anyone is interested.

Right now, I've put together a very basic and currently useless implementation. It needs to be populated with Components to see the selection mechanism at work.


To use the `LassoComponent`, you have to reimplement `LassoSource<...>`, I find it convenient to use `<Component*>` as the type. 
To reimplement, you must override the two virtual LassoSource methods, `findLassoItemsInArea()` where you fill the given parameter array with the components you consider to be selected, in the given parameter area; `getLassoSelection()` where you return an initialised `SelectedItemSet<yourType>`. It's convenient to have this as a member of your LassoSource reimplementation class.

Then, use the `mouseDown()`, `mouseDrag()`, and `mouseUp()` overrides in your component to call the relevant `LassoComponent` methods, passing `beginLasso(event, this)` if your component reimplements `LassoSource` like in my example.


**LASSO COMPONENT**: A component that acts as a rectangular selection region, which you drag with the mouse to select groups of objects (in conjunction with a SelectedItemSet).
*https://docs.juce.com/master/classLassoComponent.html*

**LASSO SOURCE**: A class used by the LassoComponent to manage the things that it selects. 
*https://docs.juce.com/master/classLassoSource.html*

**TO-DO:**
Add components to interact with.
Add an actual selection mechanism in `findLassoItemsInArea()`. I'd like to see different possibilities with efficiency trade-offs.
Looking to add CHANGELISTENER mechanism to the SelectedItemsList. 
