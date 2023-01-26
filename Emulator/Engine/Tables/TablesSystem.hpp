#pragma once

class CTablesSystem
{
public:
	void InitializeClient();
	void InitializeRender();
	void InitializeRageBot();
	void InitializeSourceUtils();
	void InitializeEngine();
};

inline CTablesSystem g_TablesSystem;