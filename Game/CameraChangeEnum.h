#pragma once
enum CHE {
	NONE,
	PLUS,
	MINUS
};


struct CHE_VALUES
{
	CHE rChange = CHE::NONE;
	CHE thetaChange = CHE::NONE;
	CHE phiChange = CHE::NONE;
	CHE pitchChange = CHE::NONE;
	CHE yawChange = CHE::NONE;
	CHE rollChange = CHE::NONE;
};