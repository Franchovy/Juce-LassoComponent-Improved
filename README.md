# Juce LassoComponent Improved

Example use of JUCE LassoComponent, and LassoSource, with accompanying classes and override. 

I personally found that this class was slow and didn't function that well. With large outlines, the `repaint()` function would slow down the app a lot. The temporary solution to this is for the lasso to only be a dotted outline - this already speeds up the GUI. 

I also included a useful model class I use - "SelectableHoverableComponent". This, as the name implies, is selectable and hoverable based on mouse input. The class also statically manages the selected components. I will use this project to make sure these classes are optimized.

The JUCE LassoComponent is also broken because it strictly uses the selectable bounds rather than `hitTest(x, y)`, which means components that aren't meant to be selected sometimes are. In this project I plan to correct this behaviour.

TODO: 
. Customize the repaint so it specifically targets the outline of the Lasso. Also apply to SelectableHoverableComponent. 
. Add an actual selection mechanism in `findLassoItemsInArea()`.
. Fix the hitTest vs. bounds selection issue.
