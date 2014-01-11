/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*- */
/*
 * This file is part of the libabw project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef TEXTDOCUMENTGENERATOR_H
#define TEXTDOCUMENTGENERATOR_H

#include <libwpd/libwpd.h>
#include <libwpd-stream/libwpd-stream.h>

class TextDocumentGenerator : public WPXDocumentInterface
{
public:
  TextDocumentGenerator(const bool isInfo=false);
  virtual ~TextDocumentGenerator();

  virtual void setDocumentMetaData(const WPXPropertyList &propList);

  virtual void startDocument() {}
  virtual void endDocument() {}

  virtual void definePageStyle(const WPXPropertyList &) {}
  virtual void openPageSpan(const WPXPropertyList & /* propList */) {}
  virtual void closePageSpan() {}
  virtual void openHeader(const WPXPropertyList & /* propList */) {}
  virtual void closeHeader() {}
  virtual void openFooter(const WPXPropertyList & /* propList */) {}
  virtual void closeFooter() {}

  virtual void defineSectionStyle(const WPXPropertyList &, const WPXPropertyListVector &) {}
  virtual void openSection(const WPXPropertyList & /* propList */, const WPXPropertyListVector & /* columns */) {}
  virtual void closeSection() {}

  virtual void defineParagraphStyle(const WPXPropertyList &, const WPXPropertyListVector &) {}
  virtual void openParagraph(const WPXPropertyList & /* propList */, const WPXPropertyListVector & /* tabStops */) {}
  virtual void closeParagraph();

  virtual void defineCharacterStyle(const WPXPropertyList &) {}
  virtual void openSpan(const WPXPropertyList & /* propList */) {}
  virtual void closeSpan() {}

  virtual void insertTab();
  virtual void insertText(const WPXString &text);
  virtual void insertSpace();
  virtual void insertLineBreak();
  virtual void insertField(const WPXString & /* type */, const WPXPropertyList & /* propList */) {}

  virtual void defineOrderedListLevel(const WPXPropertyList & /* propList */) {}
  virtual void defineUnorderedListLevel(const WPXPropertyList & /* propList */) {}
  virtual void openOrderedListLevel(const WPXPropertyList & /* propList */) {}
  virtual void openUnorderedListLevel(const WPXPropertyList & /* propList */) {}
  virtual void closeOrderedListLevel() {}
  virtual void closeUnorderedListLevel() {}
  virtual void openListElement(const WPXPropertyList & /* propList */, const WPXPropertyListVector & /* tabStops */) {}
  virtual void closeListElement() {}

  virtual void openFootnote(const WPXPropertyList & /* propList */) {}
  virtual void closeFootnote() {}
  virtual void openEndnote(const WPXPropertyList & /* propList */) {}
  virtual void closeEndnote() {}
  virtual void openComment(const WPXPropertyList & /* propList */) {}
  virtual void closeComment() {}
  virtual void openTextBox(const WPXPropertyList & /* propList */) {}
  virtual void closeTextBox() {}

  virtual void openTable(const WPXPropertyList & /* propList */, const WPXPropertyListVector & /* columns */) {}
  virtual void openTableRow(const WPXPropertyList & /* propList */) {}
  virtual void closeTableRow() {}
  virtual void openTableCell(const WPXPropertyList & /* propList */) {}
  virtual void closeTableCell() {}
  virtual void insertCoveredTableCell(const WPXPropertyList & /* propList */) {}
  virtual void closeTable() {}

  virtual void openFrame(const WPXPropertyList & /* propList */) {}
  virtual void closeFrame() {}

  virtual void insertBinaryObject(const WPXPropertyList & /* propList */, const WPXBinaryData & /* object */) {}
  virtual void insertEquation(const WPXPropertyList & /* propList */, const WPXString & /* data */) {}

private:
  bool m_isInfo;
};

#endif /* TEXTDOCUMENTGENERATOR_H */
/* vim:set shiftwidth=2 softtabstop=2 expandtab: */
