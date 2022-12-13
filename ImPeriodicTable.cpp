
#include <cstdint>
#include "imgui.h"

#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui_internal.h"

#if defined USE_IMGUI
  #include "Debug/ImGuiAux.h"
#endif




constexpr float kWindowInitWidth=1280.0f;
constexpr float kWindowInitHeight=850.0f;
constexpr float kElementsColumns=18.0f;
constexpr float kElementBorder=2.0f;
constexpr float kElementSeparation=4.0f;


struct Element
{
  int         m_AtomicNumber;
  const char* m_Simbol;
  const char* m_Name;
  float       m_AtomicMass;
  const int*  m_Electrons;

  int         m_PosX,m_PosY;
  uint32_t    m_Colour;
  uint32_t    m_State;
};


constexpr uint32_t kNoMetal  = IM_COL32(92,151,209,255);
constexpr uint32_t kNobleGas = IM_COL32(32,182,233,255);
constexpr uint32_t kHalogen  = IM_COL32(212,91,163,255);
constexpr uint32_t kAlkaline = IM_COL32(246,125,34,255);
constexpr uint32_t kAlkalineEarth = IM_COL32(251,197,75,255);
constexpr uint32_t kLanthanide = IM_COL32(0,169,150,255);
constexpr uint32_t kActinide = IM_COL32(121,197,148,255);
constexpr uint32_t kMetalloid = IM_COL32(155,144,85,255);
constexpr uint32_t kMetalTransition = IM_COL32(134,195,91,255);
constexpr uint32_t kMetalP = IM_COL32(255,244,85,255);


constexpr uint32_t kGas     = IM_COL32(220,120,120,255);
constexpr uint32_t kLiquid  = IM_COL32(120,120,220,255);
constexpr uint32_t kSolid   = IM_COL32(240,240,240,255);
constexpr uint32_t kUnknown = IM_COL32(86,86,86,255);


constexpr int kElectronsH[]={1,1};
constexpr int kElectronsHe[]={1,2};
constexpr int kElectronsLi[]={2,2,1};
constexpr int kElectronsBe[]={2,2,2};
constexpr int kElectronsB[]={2,2,3};
constexpr int kElectronsC[]={2,2,4};
constexpr int kElectronsN[]={2,2,5};
constexpr int kElectronsO[]={2,2,6};
constexpr int kElectronsF[]={2,2,7};
constexpr int kElectronsNe[]={2,2,8};
constexpr int kElectronsNa[]={3,2,8,1};
constexpr int kElectronsMg[]={3,2,8,2};
constexpr int kElectronsAl[]={3,2,8,3};
constexpr int kElectronsSi[]={3,2,8,4};
constexpr int kElectronsP[]={3,2,8,5};
constexpr int kElectronsS[]={3,2,8,6};
constexpr int kElectronsCl[]={3,2,8,7};
constexpr int kElectronsAr[]={3,2,8,8};
constexpr int kElectronsK[]={4,2,8,8,1};
constexpr int kElectronsCa[]={4,2,8,8,2};
constexpr int kElectronsSc[]={4,2,8,8,3};
constexpr int kElectronsTi[]={4,2,8,10,2};
constexpr int kElectronsV[]={4,2,8,11,2};
constexpr int kElectronsCr[]={4,2,8,13,1};
constexpr int kElectronsMn[]={4,2,8,13,2};
constexpr int kElectronsFe[]={4,2,8,14,2};
constexpr int kElectronsCo[]={4,2,8,15,2};
constexpr int kElectronsNi[]={4,2,8,16,2};
constexpr int kElectronsCu[]={4,2,8,18,1};
constexpr int kElectronsZn[]={4,2,8,18,2};
constexpr int kElectronsGa[]={4,2,8,18,3};
constexpr int kElectronsGe[]={4,2,8,18,4};
constexpr int kElectronsAs[]={4,2,8,18,5};
constexpr int kElectronsSe[]={4,2,8,18,6};
constexpr int kElectronsBr[]={4,2,8,18,7};
constexpr int kElectronsKr[]={4,2,8,18,8};
constexpr int kElectronsRb[]={5,2,8,18,8,1};
constexpr int kElectronsSr[]={5,2,8,18,8,2};
constexpr int kElectronsY[] ={5,2,8,18,9,2};
constexpr int kElectronsZr[]={5,2,8,18,10,2};
constexpr int kElectronsNb[]={5,2,8,18,12,1};
constexpr int kElectronsMo[]={5,2,8,18,13,1};
constexpr int kElectronsTc[]={5,2,8,18,1,1};
constexpr int kElectronsRu[]={5,2,8,18,15,1};
constexpr int kElectronsRh[]={5,2,8,18,16,1};
constexpr int kElectronsPd[]={4,2,8,18,18};
constexpr int kElectronsAg[]={5,2,8,18,18,1};
constexpr int kElectronsCd[]={5,2,8,18,18,2};
constexpr int kElectronsIn[]={5,2,8,18,18,3};
constexpr int kElectronsSn[]={5,2,8,18,18,4};
constexpr int kElectronsSb[]={5,2,8,18,18,5};
constexpr int kElectronsTe[]={5,2,8,18,18,6};
constexpr int kElectronsI[] ={5,2,8,18,18,7};
constexpr int kElectronsXe[]={5,2,8,18,18,8};
constexpr int kElectronsCs[]={6,2,8,18,18,8,1};
constexpr int kElectronsBa[]={6,2,8,18,18,8,2};
constexpr int kElectronsLa[]={6,2,8,18,18,9,2};
constexpr int kElectronsCe[]={6,2,8,18,18,9,1};
constexpr int kElectronsPr[]={6,2,8,18,21,8,2};
constexpr int kElectronsNd[]={6,2,8,18,22,8,2};
constexpr int kElectronsPm[]={6,2,8,18,23,8,2};
constexpr int kElectronsSm[]={6,2,8,18,24,8,2};
constexpr int kElectronsEu[]={6,2,8,18,25,8,2};
constexpr int kElectronsGd[]={6,2,8,18,25,9,2};
constexpr int kElectronsTb[]={6,2,8,18,27,8,2};
constexpr int kElectronsDy[]={6,2,8,18,28,8,2};
constexpr int kElectronsHo[]={6,2,8,18,29,8,2};
constexpr int kElectronsEr[]={6,2,8,18,30,8,2};
constexpr int kElectronsTm[]={6,2,8,18,31,8,2};
constexpr int kElectronsYb[]={6,2,8,18,32,8,2};
constexpr int kElectronsLu[]={6,2,8,18,32,9,2};
constexpr int kElectronsHf[]={6,2,8,18,32,10,2};
constexpr int kElectronsTa[]={6,2,8,18,32,11,2};
constexpr int kElectronsW[] ={6,2,8,18,32,12,2};
constexpr int kElectronsRe[]={6,2,8,18,32,13,2};
constexpr int kElectronsOs[]={6,2,8,18,32,14,2};
constexpr int kElectronsIr[]={6,2,8,18,32,15,2};
constexpr int kElectronsPt[]={6,2,8,18,32,17,1};
constexpr int kElectronsAu[]={6,2,8,18,32,18,1};
constexpr int kElectronsHg[]={6,2,8,18,32,18,2};
constexpr int kElectronsTl[]={6,2,8,18,32,18,3};
constexpr int kElectronsPb[]={6,2,8,18,32,18,4};
constexpr int kElectronsBi[]={6,2,8,18,32,18,5};
constexpr int kElectronsPo[]={6,2,8,18,32,18,6};
constexpr int kElectronsAt[]={6,2,8,18,32,18,7};
constexpr int kElectronsRn[]={6,2,8,18,32,18,8};

constexpr int kElectronsFr[]={7,2,8,18,32,18,8,1};
constexpr int kElectronsRa[]={7,2,8,18,32,18,8,2};
constexpr int kElectronsAc[]={7,2,8,18,32,18,9,2};
constexpr int kElectronsTh[]={7,2,8,18,32,18,10,2};
constexpr int kElectronsPa[]={7,2,8,18,32,20,9,2};
constexpr int kElectronsU[] ={7,2,8,18,32,21,9,2};
constexpr int kElectronsNp[]={7,2,8,18,32,22,9,2};
constexpr int kElectronsPu[]={7,2,8,18,32,24,8,2};
constexpr int kElectronsAm[]={7,2,8,18,32,25,8,2};
constexpr int kElectronsCm[]={7,2,8,18,32,25,9,2};
constexpr int kElectronsBk[]={7,2,8,18,32,27,8,2};
constexpr int kElectronsCf[]={7,2,8,18,32,28,8,2};
constexpr int kElectronsEs[]={7,2,8,18,32,29,8,2};
constexpr int kElectronsFm[]={7,2,8,18,32,30,8,2};
constexpr int kElectronsMd[]={7,2,8,18,32,31,8,2};
constexpr int kElectronsNo[]={7,2,8,18,32,32,8,2};
constexpr int kElectronsLr[]={7,2,8,18,32,32,8,3};
constexpr int kElectronsRf[]={7,2,8,18,32,32,10,2};
constexpr int kElectronsDb[]={7,2,8,18,32,32,11,2};
constexpr int kElectronsSg[]={7,2,8,18,32,32,12,2};
constexpr int kElectronsBh[]={7,2,8,18,32,32,13,2};
constexpr int kElectronsHs[]={7,2,8,18,32,32,16,2};
constexpr int kElectronsMt[]={7,2,8,18,32,32,15,2};
constexpr int kElectronsDs[]={7,2,8,18,32,32,16,2};
constexpr int kElectronsRg[]={7,2,8,18,32,32,17,2};
constexpr int kElectronsCn[]={7,2,8,18,32,32,18,2};
constexpr int kElectronsNh[]={7,2,8,18,32,18,18,3};
constexpr int kElectronsFl[]={7,2,8,18,32,32,18,4};
constexpr int kElectronsMc[]={7,2,8,18,32,32,18,5};
constexpr int kElectronsLv[]={7,2,8,18,32,32,18,6};
constexpr int kElectronsTs[]={7,2,8,18,32,32,18,7};
constexpr int kElectronsOg[]={7,2,8,18,32,32,18,8};




constexpr Element kPeridicTable[]
{
  {1,  "H",  "Hidrogeno",    0.0f, kElectronsH,    0, 0, kNoMetal,         kGas},
  {2,  "He", "Helio",        0.0f, kElectronsHe,   17,0, kNobleGas,        kGas},
  {2,  "Li", "Litio",        0.0f, kElectronsLi,   0, 1, kAlkaline,        kSolid},
  {4,  "Be", "Berilio",      0.0f, kElectronsBe,   1, 1, kAlkalineEarth,   kSolid},
  {5,  "B",  "Boro",         0.0f, kElectronsB,   12,1,  kMetalloid,       kSolid},
  {6,  "C",  "Carbono",      0.0f, kElectronsC,   13,1,  kNoMetal,         kSolid},
  {7,  "N",  "Nitrogeno",    0.0f, kElectronsN,   14,1,  kNoMetal,         kGas},
  {8,  "O",  "Oxigeno",      0.0f, kElectronsO,   15,1,  kNoMetal,         kGas},
  {9,  "F",  "Fluor",        0.0f, kElectronsF,   16,1,  kHalogen,         kGas},
  {10, "Ne", "Neon",         0.0f, kElectronsNe,   17,1, kNobleGas,        kGas},
  {11, "Na", "Sodio",        0.0f, kElectronsNa,   0 ,2, kAlkaline,        kSolid},
  {12, "Mg", "Magnesio",     0.0f, kElectronsMg,   1 ,2, kAlkalineEarth,   kSolid},
  {13, "Al", "Aluminio",     0.0f, kElectronsAl,   12,2, kMetalP,          kSolid},
  {14, "Si", "Silicio",      0.0f, kElectronsSi,   13,2, kMetalloid,       kSolid},
  {15, "P",  "Fosforo",      0.0f, kElectronsP,    14,2, kNoMetal,         kSolid},
  {16, "S",  "Azufre",       0.0f, kElectronsS,    15,2, kNoMetal,         kSolid},
  {17, "Cl", "Cloro",        0.0f, kElectronsCl,   16,2, kHalogen,         kGas},
  {18, "Ar", "Argon",        0.0f, kElectronsAr,   17,2, kNobleGas,        kGas},
  {19, "K",  "Potasio",      0.0f, kElectronsK,    0, 3, kAlkaline,        kSolid},
  {20, "Ca", "Calcio",       0.0f, kElectronsCa,   1, 3, kAlkalineEarth,   kSolid},
  {21, "Sc", "Escandio",     0.0f, kElectronsSc,   2, 3, kMetalTransition, kSolid},
  {22, "Ti", "Titanio",      0.0f, kElectronsTi,   3, 3, kMetalTransition, kSolid},
  {23, "V",  "Vanadio",      0.0f, kElectronsV,    4, 3, kMetalTransition, kSolid},
  {24, "Cr", "Cromo",        0.0f, kElectronsCr,   5, 3, kMetalTransition, kSolid},
  {25, "Mn", "Manganeso",    0.0f, kElectronsMn,   6, 3, kMetalTransition, kSolid},
  {26, "Fe", "Hierro",       0.0f, kElectronsFe,   7, 3, kMetalTransition, kSolid},
  {27, "Co", "Cobalto",      0.0f, kElectronsCo,   8, 3, kMetalTransition, kSolid},
  {28, "Ni", "Niquel",       0.0f, kElectronsNi,   9, 3, kMetalTransition, kSolid},
  {29, "Cu", "Cobre",        0.0f, kElectronsCu,   10,3, kMetalTransition, kSolid},
  {30, "Zn", "Zinc",         0.0f, kElectronsZn,   11,3, kMetalTransition, kSolid},
  {31, "Ga", "Galio",        0.0f, kElectronsGa,   12,3, kMetalP,          kLiquid},
  {32, "Ge", "Germanio",     0.0f, kElectronsGe,   13,3, kMetalloid,       kSolid},
  {33, "As", "Arsenico",     0.0f, kElectronsAs,   14,3, kMetalloid,       kSolid},
  {34, "Se", "Selenio",      0.0f, kElectronsSe,   15,3, kNoMetal,         kSolid},
  {35, "Br", "Bromo",        0.0f, kElectronsBr,   16,3, kHalogen,         kLiquid},
  {36, "Kr", "Kripton",      0.0f, kElectronsKr,   17,3, kNobleGas,        kGas},
  {37, "Rb", "Rubidio",      0.0f, kElectronsRb,   0 ,4, kAlkaline,        kSolid},
  {38, "Sr", "Estroncio",    0.0f, kElectronsSr,   1 ,4, kAlkalineEarth,   kSolid},
  {39, "Y",  "Itrio",        0.0f, kElectronsY,    2 ,4, kMetalTransition, kSolid},
  {40, "Zr", "Circonio",     0.0f, kElectronsZr,   3 ,4, kMetalTransition, kSolid},
  {41, "Nb", "Niobio",       0.0f, kElectronsNb,   4 ,4, kMetalTransition, kSolid},
  {42, "Mo", "Molibdeno",    0.0f, kElectronsMo,   5 ,4, kMetalTransition, kSolid},
  {43, "Tc", "Tecnecio",     0.0f, kElectronsTc,   6 ,4, kMetalTransition, kSolid},
  {44, "Ru", "Rutenio",      0.0f, kElectronsRu,   7 ,4, kMetalTransition, kSolid},
  {45, "Rh", "Rodio",        0.0f, kElectronsRh,   8 ,4, kMetalTransition, kSolid},
  {46, "Pd", "Paladio",      0.0f, kElectronsPd,   9 ,4, kMetalTransition, kSolid},
  {47, "Ag", "Plata",        0.0f, kElectronsAg,   10,4, kMetalTransition, kSolid},
  {48, "Cd", "Cadmio",       0.0f, kElectronsCd,   11,4, kMetalTransition, kSolid},
  {49, "In", "Indio",        0.0f, kElectronsIn,   12,4, kMetalP,          kSolid},
  {50, "Sn", "Estaño",       0.0f, kElectronsSn,   13,4, kMetalP,          kSolid},
  {51, "Sb", "Antimonio",    0.0f, kElectronsSb,   14,4, kMetalloid,       kSolid},
  {52, "Te", "Telurio",      0.0f, kElectronsTe,   15,4, kMetalloid,       kSolid},
  {53, "I",  "Yodo",         0.0f, kElectronsI,    16,4, kHalogen,         kSolid},
  {54, "Xe", "Xenon",        0.0f, kElectronsXe,   17,4, kNobleGas,        kGas},
  {55, "Cs", "Cesio",        0.0f, kElectronsCs,   0 ,5, kAlkaline,        kLiquid},
  {56, "Ba", "Bario",        0.0f, kElectronsBa,   1 ,5, kAlkalineEarth,   kSolid},
  {72, "Hf", "Hafnio",       0.0f, kElectronsHf,   3 ,5, kMetalTransition, kSolid},
  {73, "Ta", "Tantalio",     0.0f, kElectronsTa,   4 ,5, kMetalTransition, kSolid},
  {74, "W",  "Wolframio",    0.0f, kElectronsW,    5 ,5, kMetalTransition, kSolid},
  {75, "Re", "Renio",        0.0f, kElectronsRe,   6 ,5, kMetalTransition, kSolid},
  {76, "Os", "Osmio",        0.0f, kElectronsOs,   7 ,5, kMetalTransition, kSolid},
  {77, "Ir", "Iridio",       0.0f, kElectronsIr,   8 ,5, kMetalTransition, kSolid},
  {78, "Pt", "Platino",      0.0f, kElectronsPt,   9 ,5, kMetalTransition, kSolid},
  {79, "Au", "Oro",          0.0f, kElectronsAu,   10,5, kMetalTransition, kSolid},
  {80, "Hg", "Mercurio",     0.0f, kElectronsHg,   11,5, kMetalTransition, kLiquid},
  {81, "Tl", "Talio",        0.0f, kElectronsTl,   12,5, kMetalP,          kSolid},
  {82, "Pb", "Plomo",        0.0f, kElectronsPb,   13,5, kMetalP,          kSolid},
  {83, "Bi", "Bismuto",      0.0f, kElectronsBi,   14,5, kMetalP,          kSolid},
  {84, "Po", "Polonio",      0.0f, kElectronsPo,   15,5, kMetalloid,       kSolid},
  {85, "At", "Astato",       0.0f, kElectronsAt,   16,5, kHalogen,         kSolid},
  {86, "Rn", "Radon",        0.0f, kElectronsRn,   17,5, kNobleGas,        kGas},
  {87, "Fr", "Francio",      0.0f, kElectronsFr,   0, 6, kAlkaline,        kLiquid},
  {88, "Ra", "Radio",        0.0f, kElectronsRa,   1, 6, kAlkalineEarth,   kSolid},
  {104,"Rf", "Rutherfodio",  0.0f, kElectronsRf,   3, 6, kMetalTransition, kUnknown},
  {105,"Db", "Dubnio",       0.0f, kElectronsDb,   4, 6, kMetalTransition, kUnknown},
  {106,"Sg", "Seaborgio",    0.0f, kElectronsSg,   5, 6, kMetalTransition, kUnknown},
  {107,"Bh", "Bohrio",       0.0f, kElectronsBh,   6, 6, kMetalTransition, kUnknown},
  {108,"Hs", "Hasio",        0.0f, kElectronsHs,   7, 6, kMetalTransition, kUnknown},
  {109,"Mt", "Meitnerio",    0.0f, kElectronsMt,   8, 6, kMetalTransition, kUnknown},
  {110,"Ds", "Damstadio",    0.0f, kElectronsDs,   9, 6, kMetalTransition, kUnknown},
  {111,"Rg", "Roentgenio",   0.0f, kElectronsRg,   10,6, kMetalTransition, kUnknown},
  {112,"Cn", "Copernicio",   0.0f, kElectronsCn,   11,6, kMetalTransition, kUnknown},
  {113,"Nh", "Nihonio",      0.0f, kElectronsNh,   12,6, kMetalP,          kUnknown},
  {114,"Fl", "Flerocio",     0.0f, kElectronsFl,   13,6, kMetalP,          kUnknown},
  {115,"Mc", "Moscovio",     0.0f, kElectronsMc,   14,6, kMetalP,          kUnknown},
  {116,"Lv", "Livermorio",   0.0f, kElectronsLv,   15,6, kMetalP,          kUnknown},
  {117,"Ts", "Teneso",       0.0f, kElectronsTs,   16,6, kHalogen,         kUnknown},
  {118,"Og", "Oganesón",     0.0f, kElectronsOg,   17,6, kNobleGas,        kUnknown},

  {57, "La", "Lantano",      0.0f, kElectronsLa,   2, 8, kLanthanide,      kSolid},
  {58, "Ce", "Cerio",        0.0f, kElectronsCe,   3, 8, kLanthanide,      kSolid},
  {59, "Pr", "Praseodimio",  0.0f, kElectronsPr,   4, 8, kLanthanide,      kSolid},
  {60, "Nd", "Neodimio",     0.0f, kElectronsNd,   5, 8, kLanthanide,      kSolid},
  {61, "Pm", "Prometio",     0.0f, kElectronsPm,   6, 8, kLanthanide,      kSolid},
  {62, "Sm", "Samario",      0.0f, kElectronsSm,   7, 8, kLanthanide,      kSolid},
  {63, "Eu", "Europio",      0.0f, kElectronsEu,   8, 8, kLanthanide,      kSolid},
  {64, "Gd", "Gadolimio",    0.0f, kElectronsGd,   9, 8, kLanthanide,      kSolid},
  {65, "Tb", "Terbio",       0.0f, kElectronsTb,   10,8, kLanthanide,      kSolid},
  {66, "Dy", "Disprosio",    0.0f, kElectronsDy,   11,8, kLanthanide,      kSolid},
  {67, "Ho", "Holmio",       0.0f, kElectronsHo,   12,8, kLanthanide,      kSolid},
  {68, "Er", "Erbio",        0.0f, kElectronsEr,   13,8, kLanthanide,      kSolid},
  {69, "Tm", "Tulio",        0.0f, kElectronsTm,   14,8, kLanthanide,      kSolid},
  {70, "Yb", "Iterbio",      0.0f, kElectronsYb,   15,8, kLanthanide,      kSolid},
  {71, "Lu", "Lutecio",      0.0f, kElectronsLu,   16,8, kLanthanide,      kSolid},

  {89, "Ac", "Actinio",      0.0f, kElectronsAc,   2, 9, kActinide,        kSolid},
  {90, "Th", "Thorio",       0.0f, kElectronsTh,   3, 9, kActinide,        kSolid},
  {91, "Pa", "Protactinio",  0.0f, kElectronsPa,   4, 9, kActinide,        kSolid},
  {92, "U",  "Uranio",       0.0f, kElectronsU,    5, 9, kActinide,        kSolid},
  {93, "Np", "Neptunio",     0.0f, kElectronsNp,   6, 9, kActinide,        kSolid},
  {94, "Pu", "Plutonio",     0.0f, kElectronsPu,   7, 9, kActinide,        kSolid},
  {95, "Am", "Americio",     0.0f, kElectronsAm,   8, 9, kActinide,        kSolid},
  {96, "Cm", "Curio",        0.0f, kElectronsCm,   9, 9, kActinide,        kSolid},
  {97, "Bk", "Berkelio",     0.0f, kElectronsBk,   10,9, kActinide,        kSolid},
  {98, "Cf", "Californio",   0.0f, kElectronsCf,   11,9, kActinide,        kSolid},
  {99, "Es", "Einstenio",    0.0f, kElectronsEs,   12,9, kActinide,        kSolid},
  {100,"Fm", "Fermio",       0.0f, kElectronsFm,   13,9, kActinide,        kSolid},
  {101,"Md", "Mendelevio",   0.0f, kElectronsMd,   14,9, kActinide,        kSolid},
  {102,"No", "Nobelio",      0.0f, kElectronsNo,   15,9, kActinide,        kSolid},
  {103,"Lr", "Lawrencio",    0.0f, kElectronsLr,   16,9, kActinide,        kSolid},
};




const ImVec4 kLabelColour(1.0f,1.0f,1.0f,1.0f);
const ImVec4 kTextColour(1.0f,1.0f,0.7f,1.0f);


//#define  IMGUI_BUTTON

#if !defined IMGUI_BUTTON
static bool HollowButton(const char* aText,float aWidth,float aHeight,uint32_t aColour,uint32_t aTextColour,ImGuiButtonFlags aFlags=ImGuiButtonFlags_None)
{
  ImGuiContext& g = *GImGui;
  const ImGuiStyle& style = g.Style;

  const ImVec2 size_arg(aWidth,aHeight);
  const ImVec2 label_size = ImGui::CalcTextSize(aText, NULL, true);
  ImVec2 size = ImGui::CalcItemSize(size_arg, label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);

  ImGuiWindow* window = ImGui::GetCurrentWindow();
  const ImGuiID id = window->GetID(aText);
  ImVec2 pos = window->DC.CursorPos;

  const ImRect bb(pos, pos + size);
  ImGui::ItemSize(size, style.FramePadding.y);
  if (!ImGui::ItemAdd(bb, id))
      return false;

  bool hovered, held;
  bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, aFlags);

  ImGui::RenderNavHighlight(bb, id);

  ImRect rect_inner=bb;
  rect_inner.Min.x+=aWidth/10.0f;
  rect_inner.Min.y+=aWidth/10.0f;
  rect_inner.Max.x-=aHeight/10.0f;
  rect_inner.Max.y-=aHeight/10.0f;

  if(held || hovered)
    {
      window->DrawList->AddRectFilled(bb.Min,bb.Max,aColour,0.0f);
      ImGui::PushStyleColor(ImGuiCol_Text,IM_COL32(10,10,10,255));
    }
  else
    {
      ImGui::RenderRectFilledWithHole(window->DrawList,bb,rect_inner,aColour,0.0f);
      ImGui::PushStyleColor(ImGuiCol_Text,aTextColour);
    }

  ImGui::RenderTextClipped(bb.Min+style.FramePadding,bb.Max-style.FramePadding,aText,NULL,&label_size,style.ButtonTextAlign,&bb);
  ImGui::PopStyleColor();

  return pressed;
}
#endif




static bool Button(const Element& aElement,float aWidth,float aHeight,ImGuiWindow* aWindow)
{
  ImVec2 pos((aWidth+kElementBorder+kElementSeparation)*aElement.m_PosX
            ,(aHeight+kElementBorder+kElementSeparation)*aElement.m_PosY);
  aWindow->DC.CursorPos=pos+aWindow->DC.CursorStartPos;



#if defined IMGUI_BUTTON
  ImGuiContext& g = *GImGui;
  g.Style.FrameBorderSize=1.0f;
  ImGui::PushStyleColor(ImGuiCol_Button, aElement.m_Colour);
  ImGui::PushStyleColor(ImGuiCol_Border,IM_COL32(0,0,0,255));
  ImGui::PushStyleColor(ImGuiCol_Text,aElement.m_State);

  bool ret=ImGui::ButtonEx(aElement.m_Simbol,ImVec2(aWidth,aHeight),ImGuiButtonFlags_None);
  ImGui::PopStyleColor(3);
#else
  bool ret=HollowButton(aElement.m_Simbol,aWidth,aHeight,aElement.m_Colour,aElement.m_State);  
#endif

  return ret;
}




static void ElementPopup(const Element& aElement)
{
  float wwidth=ImGui::GetWindowWidth();
  float font_scale=wwidth/(kWindowInitWidth*0.6f);

  ImGui::Dummy(ImVec2(20.0,0.0f));
  ImGui::SameLine();

  ImGui::BeginChild("Info",ImVec2(wwidth*0.6f,0));
    ImGui::Dummy(ImVec2(0.0,50.0f));
    ImGui::SetWindowFontScale(3.9f);
    ImGui::TextColored(kTextColour,"%s",aElement.m_Name);
    ImGui::NewLine();
    ImGui::Dummy(ImVec2(50.0,0.0f));


    ImGui::SetWindowFontScale(font_scale);
    if(ImGui::BeginTable("elements_data",2))
      {
        ImGui::TableSetupColumn("Title",ImGuiTableColumnFlags_WidthStretch,0.4f);
        ImGui::TableSetupColumn("Content",ImGuiTableColumnFlags_WidthStretch,0.6f);

        ImGui::TableNextRow();

          ImGui::TableNextColumn();
          ImGui::TextColored(kLabelColour,"%s","Número atómico");
          ImGui::TableNextColumn();
          ImGui::TextColored(kTextColour,"%d",aElement.m_AtomicNumber);

        ImGui::TableNextRow();

          ImGui::TableNextColumn();
          ImGui::TextColored(kLabelColour,"%s","Estado");
          ImGui::TableNextColumn();
          ImGui::TextColored(kTextColour,"%s",aElement.m_State==kSolid?  "Solido":
                                              aElement.m_State==kGas?    "Gas":
                                              aElement.m_State==kLiquid? "Liquido":
                                                                         "Desconocido"
                             );

          ImGui::TableNextRow();

            ImGui::TableNextColumn();
            ImGui::TextColored(kLabelColour,"%s","Orbitas");
            ImGui::TableNextColumn();
            ImGui::TextColored(kTextColour,"%d",aElement.m_Electrons[0]);

        ImGui::EndTable();
      }

  ImGui::EndChild();

  ImGui::SameLine();  

  ImGui::BeginChild("Info2",ImVec2(wwidth*0.5f,0));

    ImGuiWindow* window = ImGui::GetCurrentWindow();

    ImDrawList* draw_list=ImGui::GetForegroundDrawList(window);

    ImVec2 center=window->DC.CursorPos+window->Size*0.5f;
    center.x*=0.9f;

    float radius_nucleus=window->Size.x/(8.0f*2.0f);
    float radius_electron=radius_nucleus*0.3f;
    draw_list->AddCircleFilled(center,radius_nucleus*1.2f,aElement.m_Colour);
    draw_list->AddCircle(center,radius_nucleus*1.2f,IM_COL32(0,0,0,255));

    ImGui::SetWindowFontScale(font_scale*2.0f);
    ImVec2 text_size=ImGui::CalcTextSize(aElement.m_Simbol);
    draw_list->AddText(center-text_size*0.5f,IM_COL32(0,0,0,255),aElement.m_Simbol);

    int n_orbits=aElement.m_Electrons[0];

    static float ang_anim_acum = 0.0f;
    ang_anim_acum+=ImGui::GetIO().DeltaTime;
    float ang_anim=ang_anim_acum;

    for(int k=0;k<n_orbits;++k)
      {
        float r=radius_nucleus*(k+2);
        draw_list->AddCircle(center,r,IM_COL32(50,50,50,255));

        ang_anim*=-0.6f;
        int n_electrons_orbit=aElement.m_Electrons[k+1];
        for(int e=0;e<n_electrons_orbit;++e)
          {
            float angle=(2.0f*IM_PI/n_electrons_orbit);
            draw_list->AddCircleFilled(ImVec2(center.x+r*cos(e*angle+(IM_PI*1.5f)+ang_anim)
                                             ,center.y+r*sin(e*angle+(IM_PI*1.5f)+ang_anim))
                                       ,radius_electron,IM_COL32(40,40,80,255));
          }
      }

  ImGui::EndChild();
}












void ShowPeriodicTable()
{
  ImGui::SetNextWindowPos(ImVec2(0.0f,0.0f),ImGuiCond_Appearing);
  ImGui::SetNextWindowSize(ImVec2(kWindowInitWidth,kWindowInitHeight),ImGuiCond_Appearing);
  if(ImGui::Begin("Test",nullptr/*,ImGuiWindowFlags_NoTitleBar|ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoMove/*|ImGuiWindowFlags_NoBackground*/))
    {
      ImGuiWindow* window = ImGui::GetCurrentWindow();

      float window_width=ImGui::GetWindowWidth();
      float window_height=ImGui::GetWindowHeight();

      ImGui::SetWindowFontScale(1.4f*window_width/kWindowInitWidth);

      float kElementWidth=(window_width-2.0f*kElementsColumns*kElementBorder-(kElementsColumns-1.0f)*kElementSeparation)/kElementsColumns;
      float kElementHeight=kElementWidth;

      if(!window->SkipItems)
        {
          for(const Element& element:kPeridicTable)
            {
              if(Button(element,kElementWidth,kElementHeight,window))
                {
                  ImGui::OpenPopup(element.m_Name);
                }
              if (ImGui::BeginPopupModal(element.m_Name,nullptr,ImGuiWindowFlags_AlwaysAutoResize))
                {
                  const float popup_width=window_width*0.7f;
                  const float popup_height=window_height*0.7f;
                  constexpr float button_width=190.f;
                  constexpr float button_height=60.f;

                  ImGui::BeginChild("popup",ImVec2(popup_width,popup_height));
                    ElementPopup(element);
                  ImGui::EndChild();

                  if (ImGui::Button("Ok", ImVec2(button_width,button_height)))
                    {
                      ImGui::CloseCurrentPopup();
                    }

                  ImGui::EndPopup();
                }
            }
        }

      ImGui::End();
    }
}


