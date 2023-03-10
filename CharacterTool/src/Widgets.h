#pragma once
#include "Engine_include.h"
#include "PlayerActor.h"
#include "SceneMgr.h"

#define GWNAME(gwclass) typeid(gwclass).name()
using namespace KGCA41B;

enum class MsgType
{
	NONE,
	OW_RES_VIEWER,
	OW_COMP_VIEWER,
};

class GwMainMenu : public KGCA41B::GuiWidget
{
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;

	MsgType msg_ = MsgType::NONE;
	ImGui::FileBrowser file_dialog;

};

class GwCharacterWindow : public KGCA41B::GuiWidget
{
public:
	virtual void Update() override;
	virtual void Render() override;
private:
	void	CharacterBoard();
	void	SelectFrame(int& max_frame, int& cur_frame);
	void	SelectVertexShader(string& id);
	void	SelectPixelShader(string& id);
	void	SelectTexture(string& id);
	void	SelectAnimation(string& id);
	void	SelectSKM(string& id);
	void	SetBoundingBox(int& x, int& y, int& z);

private:
	void SaveCharacterData(CharacterData& data);
public:
	void LoadCharacterData(string loading_data_id);
public:
	CharacterData input_character_data;
};

class GwDataViewer : public KGCA41B::GuiWidget
{
	virtual void Update() override;
	virtual void Render() override;
};

