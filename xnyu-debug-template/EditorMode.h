#pragma once

struct EditorModeAction
{
    std::string nameFull;
    std::string nameChild;
    std::string nameParent;
};

struct EditorModeActionParent
{
    std::string nameParent;
    std::vector<EditorModeAction> actions;
};

std::vector<FeatureSettingParent> editorModeSettings;

Vector3 EditorModeCameraPosition = Vector3();
Vector3 EditorModeCameraRotation = Vector3();

bool EditorModeActivated = false;

bool isRunning = false;
bool canMove = false;
bool canRotate = false;

float cameraMoveSpeed = 10.0f;

EXTERN_DLL_EXPORT void InitEditorModeSettings(const std::vector<FeatureSettingParent>& settingParent)
{

    //
    // Take the initial loaded settings from the file
    //

    editorModeSettings = settingParent;
}

EXTERN_DLL_EXPORT void GetEditorModeSettings(FeatureSettingParent* settingParent)
{

    //
    // Write the current settings into the pointer
    //

}

EXTERN_DLL_EXPORT void UpdateEditorModeSettings(FeatureSettingParent* settingParent)
{

    //
    // Take the settings and update them for this mod
    //

}

EXTERN_DLL_EXPORT void ToggleEditorModeRoutine(bool isEnabled)
{

    //
    // Routine for editormode
    //

    EditorModeActivated = isEnabled;
}

// Editor control
EXTERN_DLL_EXPORT void EditorModeMovementMoveForward()
{

}

EXTERN_DLL_EXPORT void EditorModeMovementMoveBackward()
{

}

EXTERN_DLL_EXPORT void EditorModeMovementStrifeLeft()
{

}

EXTERN_DLL_EXPORT void EditorModeMovementStrifeRight()
{

}

EXTERN_DLL_EXPORT void EditorModeMovementMoveUpwards()
{

}

EXTERN_DLL_EXPORT void EditorModeMovementMoveDownwards()
{

}

EXTERN_DLL_EXPORT void EditorModeMovementMouseXAxis(float delta)
{

}

EXTERN_DLL_EXPORT void EditorModeMovementMouseYAxis(float delta)
{

}

EXTERN_DLL_EXPORT void EditorModeMovementMouseWheelAxis(float delta)
{

}

EXTERN_DLL_EXPORT void EditorModeActionLeftClick(Point position)
{

}

EXTERN_DLL_EXPORT void EditorModeActionLeftClickDragging(Point start, Point destination, Point lastDelta)
{

}

EXTERN_DLL_EXPORT void EditorModeActionRightClick(Point position)
{

}

EXTERN_DLL_EXPORT void EditorModeActionRightClickDragging(Point start, Point destination, Point lastDelta)
{
    canRotate = true;
}

EXTERN_DLL_EXPORT void EditorModeActionMiddleClick(Point position)
{

}

EXTERN_DLL_EXPORT void EditorModeActionMiddleClickDragging(Point start, Point destination, Point lastDelta)
{

}

EXTERN_DLL_EXPORT void EditorModeActionEnterRotationMode()
{

}

EXTERN_DLL_EXPORT void EditorModeActionEnterScalingMode()
{

}

EXTERN_DLL_EXPORT void EditorModeActionEnterMovingMode()
{

}

EXTERN_DLL_EXPORT void EditorModeActionHoldingShift()
{
    isRunning = true;
}

EXTERN_DLL_EXPORT void EditorModeActionContextAction(EditorModeAction* action)
{

}

EXTERN_DLL_EXPORT void EditorModeActionUndo()
{

}

EXTERN_DLL_EXPORT void EditorModeActionRedo()
{

}


