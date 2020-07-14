#pragma once
#ifndef mirai_cpp_events_bot_leave_active_hpp_H_
#define mirai_cpp_events_bot_leave_active_hpp_H_

#include <nlohmann/json.hpp>
#include "defs/group.hpp"
#include "event_interface.hpp"

namespace Cyan
{

	/**
	 * \brief bot 主动退群
	 */
	class BotLeaveEventActive : public EventBase
	{
	public:
		Group_t Group;

		static MiraiEvent GetMiraiEvent()
		{
			return MiraiEvent::BotLeaveEventActive;
		}

		virtual bool Set(const json& j) override
		{
			this->Group.Set(j["group"]);
			return true;
		}
		virtual json ToJson() const override
		{
			json j = json::object();
			j["type"] = "BotLeaveEventActive";
			j["group"] = this->Group.ToJson();
			return j;
		}
	};

}

#endif // !mirai_cpp_events_bot_leave_active_hpp_H_