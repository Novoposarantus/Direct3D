#pragma once
#include "Box.h"

class Box2 : public Box
{
public:
	Box2( Graphics& gfx,
		float r,
		float droll,
		float dpitch,
		float dyaw,
		float dphi,
		float dtheta,
		float dchi,
		float chi,
		float theta,
		float phi,
		float sizeX,
		float sizeY,
		float sizeZ,
		Drawable* parent
	);
	Box2(const Box2& box) : boxParent(box.boxParent){
		this->r			= box.r		;			
		this->droll		= box.droll	;
		this->dpitch	= box.dpitch;
		this->dyaw		= box.dyaw	;
		this->dphi		= box.dphi	;
		this->dtheta	= box.dtheta;
		this->dchi		= box.dchi	;
		this->chi		= box.chi	;
		this->theta		= box.theta	;
		this->phi		= box.phi	;
	}
	DirectX::XMMATRIX GetTransformXM() const noexcept override;
private:
	Drawable* boxParent;
};

