game snake

How to run -
feature disabled:
./snake

feature enabled:
./snake HelpMeWin



new feaaure:
add Help Me Win - flag in main (called HelpMeWin)

documentation
add new flag as main arg to enbale the feature
add new vector (previewSteps) to snake class. that vector saved the next steps to the food.
add method calculateAndPrintPreview to save the next steps
add GetNextDirection find the next recommended step include checking border
add handlePreview to start calc
add sleep of 1 sec for display route

the route display when both conditions are met:
1-feature flag enabled
2-the snake eat the food
