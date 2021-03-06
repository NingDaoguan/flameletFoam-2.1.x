/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::hsRhoMixtureThermo

Description
    Foam::hsRhoMixtureThermo

SourceFiles
    hsRhoMixtureThermo.C

Contributors/Copyright
    2014 Hagen Müller <hagen.mueller@unibw.de>

\*---------------------------------------------------------------------------*/

#ifndef hsRhoMixtureThermo_H
#define hsRhoMixtureThermo_H

#include "hsReactionThermo.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                      Class hsRhoMixtureThermo Declaration
\*---------------------------------------------------------------------------*/

template<class MixtureType>
class hsRhoMixtureThermo
:
    public hsReactionThermo,
    public MixtureType
{
    // Private Member Functions

        void calculate();

        //- Construct as copy (not implemented)
        hsRhoMixtureThermo(const hsRhoMixtureThermo<MixtureType>&);


public:

    //- Runtime type information
    TypeName("hsRhoMixtureThermo");


    // Constructors

        //- Construct from mesh
        hsRhoMixtureThermo(const fvMesh&);


    //- Destructor
    virtual ~hsRhoMixtureThermo();


    // Member functions

        //- Return the compostion of the multi-component mixture
        virtual basicMultiComponentMixture& composition()
        {
            return *this;
        }

        //- Return the compostion of the multi-component mixture
        virtual const basicMultiComponentMixture& composition() const
        {
            return *this;
        }

        //- Update properties
        virtual void correct();


        // Fields derived from thermodynamic state variables

            //- Chemical enthalpy [J/kg]
            virtual tmp<volScalarField> hc() const;


            //- Sensible nthalpy for cell-set [J/kg]
            virtual tmp<scalarField> hs
            (
                const scalarField& T,
                const labelList& cells
            ) const;

            //- Sensible enthalpy for patch [J/kg]
            virtual tmp<scalarField> hs
            (
                const scalarField& T,
                const label patchi
            ) const;

            //- Heat capacity at constant pressure for patch [J/kg/K]
            virtual tmp<scalarField> Cp
            (
                const scalarField& T,
                const label patchi
            ) const;

            //- Heat capacity at constant pressure [J/kg/K]
            virtual tmp<volScalarField> Cp() const;

        //- Read thermophysicalProperties dictionary
        virtual bool read();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include "hsRhoMixtureThermo.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
