/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * This file is part of the libabw project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef __ABWCOLLECTOR_H__
#define __ABWCOLLECTOR_H__

#include <librevenge/librevenge.h>

namespace libabw
{

class ABWParsingState
{
public:
  ABWParsingState();
  ~ABWParsingState();

  bool m_isDocumentStarted;
  bool m_isPageSpanOpened;
  bool m_isSectionOpened;

  bool m_isSpanOpened;
  bool m_isParagraphOpened;

private:
  ABWParsingState(const ABWParsingState &);
  ABWParsingState &operator=(const ABWParsingState &);
};

class ABWCollector
{
public:
  ABWCollector(::librevenge::RVNGTextInterface *iface);
  virtual ~ABWCollector();

  // collector functions

  void closeParagraph();
  void closeSpan();
  void endSection();
  void startDocument();
  void endDocument();
  void insertLineBreak();
  void insertColumnBreak();
  void insertPageBreak();
  void insertText(const librevenge::RVNGString &text);

private:
  ABWCollector(const ABWCollector &);
  ABWCollector &operator=(const ABWCollector &);

  void _openPageSpan();
  void _closePageSpan();

  void _openSection();
  void _closeSection();

  void _openParagraph();
  void _closeParagraph();

  void _openListElement();
  void _closeListElement();

  void _openSpan();
  void _closeSpan();

  ABWParsingState *m_ps;
  librevenge::RVNGTextInterface *m_iface;

};

} // namespace libabw

#endif /* __ABWCOLLECTOR_H__ */
/* vim:set shiftwidth=2 softtabstop=2 expandtab: */