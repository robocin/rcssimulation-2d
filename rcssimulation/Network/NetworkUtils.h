//
// Created by Felipe Pereira <fnalmeidap> on 7/18/23.
// Copyright (c) 2023 RobôCIn. All rights reserved.
//
#ifndef RCSSIMULATION_NETWORKUTILS_H
#define RCSSIMULATION_NETWORKUTILS_H

#include <iostream>
#include <format>
#include <utility>

class Command {
public:
    static constexpr double NO_DIRECTION = 0.0;
    static constexpr std::string WHITESPACE = " ";
    static constexpr std::string EMPTY = "";

    class [[maybe_unused]] SideMessage {
    private:
        static constexpr std::string THEIR_SIDE = "opp";
        static constexpr std::string OUR_SIDE = "our";
    public:
        explicit SideMessage(std::string side) : value(std::move(side)) {};
        const std::string value;
    };

    static inline std::string playerInit(const std::string& teamName,
                                         const double version,
                                         const bool isGoalie = false) {

        std::string goalieParameter = isGoalie ? " (goalie)" : EMPTY;
        return std::format("(init {} (version {}){})", teamName, version, goalieParameter);
    }

    static inline std::string playerReconnect(const std::string& teamName,
                                              const u_int8_t unum) {
        return std::format("(reconnect {} {})",teamName, unum);
    }

    static inline std::string playerBye() {
        return {"(bye)"} ;
    }

    static inline std::string playerMove(const double x,
                                         const double y) {
        return std::format("(move {} {})", x, y);
    }

    static inline std::string playerDash(const double power,
                                         const double direction) {
        std::string directionParameter = WHITESPACE + std::to_string(direction);
        if (direction == NO_DIRECTION) directionParameter = EMPTY;

        return std::format("(dash {}{})", power, directionParameter);
    }

    static inline std::string playerTurn(const double moment) {
        return std::format("(turn {})", moment);
    }

    static inline std::string playerKick(const double power,
                                         const double direction) {
        return std::format("(kick {} {})", power, direction);
    }

    static inline std::string playerCatch(const double direction) {
        return std::format("(catch {})", direction);
    };

    static inline std::string playerTurnNeck(const double moment) {
        return std::format("(turn_neck {})", moment);
    }

    //todo(fnap): check synch see mode
    static inline std::string playerChangeView(const double width) {
        return std::format("(change_view {})", width);
    }

    static inline std::string playerChangeFocus(const double momentDistance,
                                                const double momentDirection) {
        return std::format("(change_focus {} {})", momentDistance, momentDirection);
    }
    //todo(fnap): handle version >= 8
    static inline std::string playerSay(const std::string& message) {
        return std::format("(say {})", message);
    }
    //todo(fnap): handle turned on or off
    static inline std::string playerPointTo(const double distance,
                                            const double direction) {
        return std::format("(pointto {} {}", distance, direction);
    }
    //todo(fnap): handle turned on or off
    static inline std::string playerAttentionTo(const Command::SideMessage& side, const u_int8_t unum) {
        return std::format("(attentionto {} {}", side.value, unum);
    }
    //todo(fnap): study and implement ear command
    static inline std::string playerEar() {
        throw std::runtime_error("Not implemented");
    }

    static inline std::string playerSenseBody() {
        return {"(sense body)"};
    }

    static inline std::string playerScore() {
        return {"(score)"};
    }
    //todo(fnap): study and implement compression command
    static inline std::string playerCompression() {
        throw std::runtime_error("Not implemented");
    }

    static inline std::string playerDone() {
        return {"(done)"};
    }
};

#endif //RCSSIMULATION_NETWORKUTILS_H
