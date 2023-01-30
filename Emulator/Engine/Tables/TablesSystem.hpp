#pragma once

class CTablesSystem
{
public:
	void InitializeGlobals();
	void InitializeClient();
	void InitializeRender();
	void InitializeRageBot();
	void InitializeSourceUtils();
	void InitializeEngine();
	void InitializeTrace();
	void InitializeGlobalVars();
	void InitializeClientState();
	void IntitializeEntityList();
};

inline CTablesSystem g_TablesSystem;