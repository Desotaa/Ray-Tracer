#pragma once

#include "Material.h"
#include "Texture.h"

class Diffuse_Light : public Material
{
public:
	Diffuse_Light(shared_ptr<Texture> emit_in) : emit(emit_in) {}
	Diffuse_Light(Color c) : emit(make_shared<Solid_Color>(c)) {}

	virtual bool scatter(const Ray &r_in, const hit_record &rec, Color &attenuation, Ray &scattered) const 
	{
		return false;
	}

	virtual Color emitted(const Ray &r_in, const hit_record &rec, double u, double v, const Point3 &p) const override
	{
		if (rec.front_face)
		{
			return emit->value(u, v, p);
		}
		else
		{
			return Color(0.0,0.0,0.0);
		}
	}

private:
	shared_ptr<Texture> emit;
};