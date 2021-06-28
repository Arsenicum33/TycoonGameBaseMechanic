
#include "GM_PlayerProperties.h"


void AGM_PlayerProperties::Collect(float Value)
{
	PlayerResourceValue += Value;
}
void AGM_PlayerProperties::Spend(float Value)
{
	PlayerResourceValue -= Value;
}
float AGM_PlayerProperties::GetPlayerResourceValue() const
{
	return PlayerResourceValue;
}