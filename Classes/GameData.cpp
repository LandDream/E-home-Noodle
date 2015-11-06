#include "GameData.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"
using namespace  rapidjson;
static GameData *game_data = nullptr;
GameData* GameData::getInstance()
{
	if (!game_data)
	{
		game_data = new (std::nothrow) GameData();
		CCASSERT(game_data, "FATAL: GameData::getInstance()");
		game_data->readData();
	}

	return game_data;
}

void GameData::readData()
{
	//std::string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("GameData.json");
	//rapidjson::Document readdoc;
	//std::string load_str;
	//ssize_t size = 0;
	//unsigned char* titlech = FileUtils::getInstance()->getFileData(path, "r", &size);
	//load_str = std::string((const char*)titlech, size);
	//if (load_str.size() < 1)
	//{
	//	createData();
	//	return;
	//}
}

void GameData::createData()
{

}

void GameData::saveData()
{

}
