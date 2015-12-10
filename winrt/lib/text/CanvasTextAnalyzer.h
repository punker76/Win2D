// Copyright (c) Microsoft Corporation. All rights reserved.
//
// Licensed under the MIT License. See LICENSE.txt in the project root for license information.

#pragma once

namespace ABI { namespace Microsoft { namespace Graphics { namespace Canvas { namespace Text
{
    class CanvasTextAnalyzer : public RuntimeClass<
        RuntimeClassFlags<WinRtClassicComMix>,
        ICanvasTextAnalyzer>,
        private LifespanTracker<CanvasTextAnalyzer>
    {
        InspectableClass(RuntimeClass_Microsoft_Graphics_Canvas_Text_CanvasTextAnalyzer, BaseTrust);

        WinString m_text;
        CanvasTextDirection m_textDirection;
        ComPtr<ICanvasTextAnalyzerOptions> m_source;
        ComPtr<ICanvasNumberSubstitution> m_defaultNumberSubstitution;
        CanvasVerticalGlyphOrientation m_defaultVerticalGlyphOrientation;
        uint32_t m_defaultBidiLevel;

    public:
        CanvasTextAnalyzer(
            HSTRING text,
            CanvasTextDirection textDirection,
            ICanvasTextAnalyzerOptions* source);

        CanvasTextAnalyzer(
            HSTRING text,
            CanvasTextDirection textDirection,
            ICanvasNumberSubstitution* numberSubstitution,
            CanvasVerticalGlyphOrientation verticalGlyphOrientation,
            uint32_t bidiLevel);

        IFACEMETHOD(ChooseFontsUsingSystemFontSet)(
            ICanvasTextFormat* textFormat,
            IVectorView<CanvasCharacterRangeFont*>** result);

        IFACEMETHOD(ChooseFonts)(
            ICanvasTextFormat* textFormat,
            ICanvasFontSet* fontSet,
            IVectorView<CanvasCharacterRangeFont*>** result);
    };


    //
    // CanvasTextTextAnalyzerFactory
    //

    class CanvasTextAnalyzerFactory
        : public ActivationFactory<ICanvasTextAnalyzerFactory>
        , private LifespanTracker<CanvasTextAnalyzerFactory>
    {
        InspectableClassStatic(RuntimeClass_Microsoft_Graphics_Canvas_Text_CanvasTextAnalyzer, BaseTrust);

    public:

        IFACEMETHOD(Create)(
            HSTRING text,
            CanvasTextDirection textDirection,
            ICanvasTextAnalyzer** textAnalyzer);

        IFACEMETHOD(CreateWithNumberSubstitutionAndVerticalGlyphOrientationAndBidiLevel)(
            HSTRING text,
            CanvasTextDirection textDirection,
            ICanvasNumberSubstitution* numberSubstitution,
            CanvasVerticalGlyphOrientation verticalGlyphOrientation,
            uint32_t bidiLevel,
            ICanvasTextAnalyzer** textAnalyzer);

        IFACEMETHOD(CreateWithOptions)(
            HSTRING text,
            CanvasTextDirection textDirection,
            ICanvasTextAnalyzerOptions* source,
            ICanvasTextAnalyzer** textAnalyzer);
    };
    
}}}}}
