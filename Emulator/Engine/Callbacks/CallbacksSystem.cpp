#include "CallbacksSystem.hpp"

void CCallbacksSystem::RegisterCallBack(std::string sName, sol::function fCallback)
{
	m_aCallbacks[sName] = fCallback;
}

void CCallbacksSystem::ClearCallbacks()
{
	m_aCallbacks.clear();
}

sol::function CCallbacksSystem::GetFunction(std::string sName)
{
	if (m_aCallbacks.find(sName) != m_aCallbacks.end())
		return m_aCallbacks[sName];

	return sol::nil;
}

std::unordered_map<std::string, sol::function> CCallbacksSystem::GetFunctions()
{
	return m_aCallbacks;
}
