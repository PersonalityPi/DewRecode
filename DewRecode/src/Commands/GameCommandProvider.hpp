#pragma once
#include <memory>
#include <ElDorito/ICommandProvider.hpp>

namespace Game
{
	enum class SetGameTypeReturnCode
	{
		Success,
		NotInLobby,
		InvalidFile,
		InvalidGameFile,
		NotFound,
		LoadFailed
	};

	class GameCommandProvider : public ICommandProvider
	{
	public:
		std::vector<std::string> MapList;

		Command* VarLanguageID;

		virtual std::vector<Command> GetCommands() override;
		virtual void RegisterVariables(ICommandManager* manager) override;

		bool CommandExit(const std::vector<std::string>& Arguments, ICommandContext& context);
		void Exit();

		bool CommandInfo(const std::vector<std::string>& Arguments, ICommandContext& context);
		std::string GetInfo();

		bool CommandVersion(const std::vector<std::string>& Arguments, ICommandContext& context);
		std::string GetVersion();

		bool CommandForceLoad(const std::vector<std::string>& Arguments, ICommandContext& context);
		bool ForceLoad(const std::string& map, Blam::GameType gameType, Blam::GameMode gameMode);

		bool CommandMap(const std::vector<std::string>& Arguments, ICommandContext& context);
		SetGameTypeReturnCode SetMap(const std::string& name);

		bool CommandGameType(const std::vector<std::string>& Arguments, ICommandContext& context);
		SetGameTypeReturnCode SetGameType(const std::string& gameType);

		bool CommandStart(const std::vector<std::string>& Arguments, ICommandContext& context);
		bool Start();
	};
}