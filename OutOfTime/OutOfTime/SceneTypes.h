#pragma once

enum class SceneType : uint8_t {
    kNone, kSplash, kTitle, kGame, kGameover
};

enum class SceneAction : uint8_t {
    kPush, kPop, kClear,
};

struct SceneChange {
    SceneAction action;
    SceneType   type;
};
